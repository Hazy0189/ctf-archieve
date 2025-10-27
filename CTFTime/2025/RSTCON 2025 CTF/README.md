# RSTCON 2025 CTF	

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| optimization | pwn | `v8` `oob` | make an float array with 1 value then call optimize 2 times to get length -1. after that just overwrite the map, size and elements of obj_array to achieve addrOf and fakeObj. then make arb write and read with fakeObj and addrOf, after that just use wasm instance code to get shell with shellcode execve. |