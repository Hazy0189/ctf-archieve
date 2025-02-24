# TRX CTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Canon Event | pwn | `stack` `ptrace` `ret2shellcode` `seccomp` `orw` | using ptrace to bypass seccomp then do orw (open sendfile) |
| Free The Monster | pwn | `heap` `stack` `environ` `ret2libc` `restricted` `house of botcake` | can only malloc and free with fixed size, using house of botcake to double free at fake chunk, then leak stack and overwrite the ret to ret2libc |
| Virtual Insanity | pwn | `stack` `ret2win` `pie` `restricted` | there is hidden mapping address at vsyscall, use it as fixed address ret, then overwrite 1 byte to win |