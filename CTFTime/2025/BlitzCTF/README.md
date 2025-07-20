# BlitzCTF

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Safe Note | pwn | `heap` `stack` `unsafe unlink` `seccomp` `orw` `one null byte` `restricted` | leak libc and heap, then do unsafe unlink to obtain an overlapping chunk. after that perform tcache poisoning to stdout and write environ  to leak the stack address. finally tcache poisoning to the return address and do open read write, before orw, close fd 0, because the seccomp only allow read fd 0. |