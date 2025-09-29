# Iran Tech Olympics CTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| pearls | pwn | `stack` `ret2gets` | bof then call gets for first time to get stdlock file in rdi then set stdlock file \x01 technique to get libc leak. after that just ret2system. |

| account management | pwn | `heap`  `uaf` `getdents` `orw` `seccomp` `restricted` | when register the same username, it will free the address but didn't clear the pointer. we can use this uaf to get content chunk in unfree content pointer chunk. then after that gain the arbitary write and read with overwrite pointer chunk. to bypass the seccomp use orw, but before that use getdents to know the filename then orw. |
