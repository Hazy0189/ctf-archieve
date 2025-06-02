# N0PSctf

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| pwnfield | pwn | `stack` `shellcode` `execve` `restricted` | there is a misaligned at starting idx shellcode when execute. using je or jne to chain the shellcode to call syscall read then jmp to rsi to get shell |
| Under Attack | pwn | `stack` `heap` `crud` `ret2system` `restricted` | since you can only create 7 idx you can't possible to get fastbin. using alloc big size to get unsorted bins then get libc and write ret2system to heap address and change the rsp to the heap address |