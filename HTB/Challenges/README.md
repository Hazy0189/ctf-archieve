# HackTheBox Challenges

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| CRSid | pwn | `hard` `heap` `exit` `malloc consolidate` | use scanf by sending 0x400 bytes to move fastbin to small bin to be leak then change the name to address of the first chunk so we have 2 chunk point to the same place. after that do tcache poison to leak the key of exit and craft fake tls payload for exit |
| Dream Diary Chapter 2 | pwn | `hard` `heap` `poison null byte attack` `got` | overlaping the chunk by using poison nullbyte attack then change the pointer struct from binary to got to get shell |
| Dream Diary Chapter 3 | pwn | `hard` `heap` `off by one null byte` `unsafe unlink` `seccomp` | use unsafe unlink to overlap the chunk then we can do tcache poisoning __free_hook -> gadget where the rdi is our register and payload using sys_execveat |
| Dream Diary Chapter 3 | pwn | `hard` `stack` `bof` `srop` `restricted` | use a gadget where it will put our input to stack and return to stack then do srop execve to get shell |