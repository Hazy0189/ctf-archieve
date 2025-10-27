from pwn import *

with open('poc.js', 'rb') as f:
    exp = f.read()

context.log_level = 'debug'
io = remote('host5.metaproblems.com', 5810)

io.sendlineafter(b':', str(len(exp)).encode())
sleep(1)
io.sendline(exp)

io.interactive()