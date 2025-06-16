# smileyCTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| blargh | pwn | `kernel` `stack` `cred` `aar` | overwrite the function of set writes to other address then bruteforce cred struct heap to get privilage escalation |
| limit | pwn | `heap` `fsop` `stdout` `unsafe unlink` `crud` `restricted` | leak libc and heap with filling tcache then do unsafe unlink to merge chunk. target the heap address tcache to leak stack and elf address, after that tcache poisoining to chunks and overwrite the pointer also the size to stdout |
| debuggable3 | pwn | `gdb` `gef` | make dummy function then replace with DW_AT_comp_dir to directory and DW_AT_name to the file target to get arbitary read file. to solve replace the function inside _start to $_shell("cat flag*")\|\|0 to get the file context and regex|