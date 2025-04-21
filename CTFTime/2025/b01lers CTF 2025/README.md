# b01lers CTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| scanner | pwn | `stack` `fmstr` `scanf` `stdout` | using fmstr to change the pointer address to stdout then leak libc and stack address after that change pointer to return address and ret2system |
| guessguesswhosstack | pwn | `stack` `www2` `fmstr` `exit` | overwrite the mangle to 0 then return to main after that main next fake tls dtor then call system /bin/sh |
