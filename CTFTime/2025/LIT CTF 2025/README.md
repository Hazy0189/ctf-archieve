# LIT CTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| the mound | pwn | `stack` `oob` `exit` | there is oob index use it to delete then create to gain arbitary write. after that targeting tls dtor exit to get shell |
| no nonsesnse | pwn | `stack` `www` `dynstr` | overwrite .dynstr strstr to string system to get shell |
| stillestprintf | pwn | `stack` `fmstr` `restricted` | since there is only one time fmstr and didn't show input, we can overwrite pointer to point to ret address then overwrite it to return to main. after that just make another pointer where ret is libc address and make it to system address |