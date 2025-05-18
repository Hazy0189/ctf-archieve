# BYUCTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Game of Yap | pwn | `stack` `putchar` `ret2system` | using yap func + 8 to leak the binary address. Next call putchar to get rsi = libc address the call yap +18 so rdi = %p. After that just ret2system to get shell |
| Goat | pwn | `stack` `GOT` `fmstr` | overwrite 2 byte got puts->main so it loops then leak libc address and do overwrite 2 byte got printf -> system. After that spam /bin/sh to get shell |
| MIPS | pwn | `MIPS` `bof` `canary` `ret2win` | break at near canary initialize then look at the register found libc address with canary inside. After that look at binary address that contain canary addr use it to leak and bof to ret2win |