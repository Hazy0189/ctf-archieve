# BackdoorCTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Gamble | pwn | `stack` `srand` `fmstr` `bof` `restricted` | the program srand() with the current time in main, so we should run the same RNG locally (using the same time seed) and hope the number of calls until rand() ≤ 0xffe is under 2000 for the remote target (need adjust the number time offset). After that login with balance (must valid writable address) // 8 and place any bet to do gamble as much the number of calls until rand() ≤ 0xffe |
| Santa's Workshop | pwn | `heap` `off by nullbyte` `unsafe unlink` | there is a off by one nullbyte in read function, do unsafe unlink to create overlapping chunnk the alloc thhe secret ad enter the code to get the flag |
| Lolimancer | pwn | `stack` `fmstr` `bof` `canary` | use the first fmstr to leak libc and stack, then the second one for leaking canary. after that just bof and ret2system |
| The Last Duel | pwn | `heap` `off by one` `exit` `stderr` `fsop` `restricted` | allocated 8 time and free it to get fastbin then use scanf to move the fastbin to libc after that overwrite the before chunk size big enough to leak libc and heap. then overwrite chunk size to 0xf0 and free 2 of it to do tcache poisoining, overwrite to stderr with add special then exit do fsop |