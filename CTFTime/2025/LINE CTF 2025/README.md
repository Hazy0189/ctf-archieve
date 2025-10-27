# LINE CTF 2025	

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Broken | pwn | `stack` `canary` `ret2libc` | get the elf leak from vs then use function to get the custom canary. after that just do bof and ret2libc to return _start, then do it again with ret2system |