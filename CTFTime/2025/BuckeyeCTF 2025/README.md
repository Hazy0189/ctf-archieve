# BuckeyeCTF 2025	

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Guessing Game | pwn | `stack` `brute force` `canary` `ret2libc` | give a big guess number then canary value, then bruteforcing guess the canary with binary search. after that just do ret2libc leak libc and ret2system |
| iloverust | pwn | `heap` `oob` `house of botcake` `got` | leak address with oob then make fake note struct with fake pointer, id and size to double free note. after that just do house of botcake and overwrite the got free to system |