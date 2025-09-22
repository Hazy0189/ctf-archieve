# K17 CTF

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| holes | pwn | `stack` `patching` `ret2shellcode` | in remote patch the binary nx to disabled then patch the printf plt bytes to jmp or call rsi. after that just give shellcode to execve |
| into the void | pwn | `stack` `bof` `srop` `restricted` | move the rsp to .bss then use got read as syscall and write the frame after it. after that overwrite one byte of got read to syscall  |