# WolvCTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Bit Burger | pwn | `stack` | basically control the rdx byte value by yes and no then rdx will be called |
| Hashmatch | pwn | `stack` `ret2system` `fmstr` | using fmstr from fprintf to write /bin/sh to bss then call ret2system (alternatively can use fgets to write /bin/sh to bss) |
| StarShip Registration | pwn | `stack` `golang` | find address that contain the win address and the offset to the stack it moved, then it will move to rdi and call the rdi |
