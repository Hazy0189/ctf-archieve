# World Wide CTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Giggity Ropity Goo | pwn | `stack` `stack pivot` `srop` `got overwrite` `restricted` | use main+31 to pivot input to the rip when got read, then input the fake frame for execve and overwrite the got read to syscall |
| Arm World | pwn | `aarch64` `bof` | use gadgets to pop from stack input to control register, then find register that also pop x30 and mov one of the pop register input to x0. after that just use system function in the main and get shell |