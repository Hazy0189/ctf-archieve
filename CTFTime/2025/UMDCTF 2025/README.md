# UMDCTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| one write | pwn | `heap` `stack` `got` `unsafe unlink` `heap overflow` | using the write function to heap overflow the first chunk to leak stack and elf address then do unsafe unlink to the chunk pointer in binary to overwrite got free->system |