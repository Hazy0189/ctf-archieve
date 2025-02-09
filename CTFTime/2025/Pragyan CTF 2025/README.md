# Preagyan CTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Dupocalypse | pwn | `stack` `socket` `ret2csu` `stack pivot` | using stackpivoting to control stack and then ret2csu for rdx. After that write flag value from stack to socket |
| Intresting | pwn | `stack` `upx` `ret2libc` `canary` `fmstr` | unpack the upx then leak address with fmstr, after that just ret2libc |
| Size Doesn't Matter | pwn | `stack` `syscall` `srop` | controling syscall with length input then use srop to execve |
| The Heap of the Brave | pwn | `heap` `overwrite` | allocate 3 times then overwrite the size to allocated next when check |