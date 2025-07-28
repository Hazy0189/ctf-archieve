# StackSmash CTF

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Its A Me Jumpio | pwn | `stack` `integer underflow` | spam w until get buy option, then buy for negative amount to get the flag |
| Jumpio Love Letter | pwn | `heap` `fmstr` `heap overflow` `fsop` `fclose` | leak with fmstr in author input then pick option four and overflow to the fp and hijack the vtable to get shell |
| Refreshments | pwn | `heap` `unsorted bins attack` `house of orange` `restricted` `one byte overflow` | using one byte overflow to create overlapping chunk then leak libc and heap also make fake vtable, after that do house of orange with unsorted bin attack |
| Super Jumpio Kart | pwn | `stack` `canary` `fmstr` `ret2system` `bof` | leak canary and libc with fmstr in other option then answer all direction to enter bof input, after that just do ret2system to get shell |
