# Infobahn CTF 2025	

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| The Butterfly Effect | pwn | `v8` `off by one` `flip bit` |  sprayed PACKED_ELEMENTS make 2 float array and obj then second array fill with fake array pointer and use the first one. after that use magic to flip the bits from PACKED_DOUBLE_ELEMENTS -> PACKED_ELEMENTS to obtain map pointer to fake array. then that just overwrite the map, size and elements of obj_array to achieve addrOf and fakeObj. make arb write and read with fakeObj and addrOf, after that just use wasm instance code to get shell with shellcode execve. |
| pwn a brainrot | pwn | `rust` `oob` `www` | send big size to obtain arbitary read write oob. then leak stack and overwrite the return address to ret2execve |