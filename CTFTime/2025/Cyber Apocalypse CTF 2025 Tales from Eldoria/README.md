# Cyber Apocalypse CTF 2025 Tales from Eldoria

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Blessing | pwn | `stack` | malloc size of the address then it will set to 0 to win |
| Contractor | pwn | `stack` `overflow` `ret2win` | overflow the buffer to touch the address so printf leak the address then ret2win |
| Crossbow | pwn | `stack` `orw` | use syscall gadget to do ORW to get flag |
| Laconic | pwn | `stack` `srop` | using srop to execve to get shell without \n need perfectly to the size input |
| Quack quack | pwn | `stack` `canary` `ret2win` | just leak the canary with perfect buffer overflow to touch then retwin with 3 byte |
| Strategist | pwn | `heap` `restricted` `heap overflow` `free hook` | malloc with full size so that when strlen at edit achieving one byte overflow, then just change size and malloc to do heap overflow |
