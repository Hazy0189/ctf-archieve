# QnQSec CTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| malloc wrapper part 1 | pwn | `stack` `heap` `integer overflow` `oob` | allocate size chunk bigger then elf address and overwrite the CACHE point to our fake struct with key, size, and target. after that target the return address and use printf fmstr to leak address then just return to main and do ret2system |
| notez | pwn | `stack` `bof` `srop` `restricted` | bof and overwrite the size to big size so that when call main where start read, we control the size read. after that just do srop to execve to get the shell |
