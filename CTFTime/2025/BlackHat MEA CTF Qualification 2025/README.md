# BlackHat MEA CTF Qual 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| File101 | pwn | `stack` `fsop` `stdout` `stderr` `restricted` | use stdout by overwriting the flag and last byte to leak libc then hijack _IO_flush_all after scanf stderr with fsop |
| calc | pwn | `heap` `oob` | input a lot of number to realloc the heap to the unsorted bins to get libc leak. then use oob to read the libc and overwrite the function pointer and change it to system to get shell. for the remote need to use io interactive to make sure it gets enough delay to not crash. |