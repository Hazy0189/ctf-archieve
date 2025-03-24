# WolvCTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| DryWall | pwn | `stack` `seccomp` `orw` | leaking libc with got address with printf then stack address with environ, do orw via syscall |
| Take Note | pwn | `heap` `fmstr` `www` `fsop` | leak address with fmstr, then making fake fp to overwrite _io_list_all with fake fp address (the intetion way is overwrite got exit with onegadget) |
