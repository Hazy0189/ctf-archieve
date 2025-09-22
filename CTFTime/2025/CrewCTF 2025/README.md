# CrewCTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| heeap banging | pwn | `heap` `crud` `calloc` `fastbin` `heap overflow` `__free_hook` `restricted` | fill tcache then overwrite next chunk so that goes to unsortedbins when free. after that use 0x83 header in the last calloc so that when calloc didn't clear the chunk to get the libc leak. then use fastbin attack to global_max_fast to leak stack address at environ. lastly target stack address contain chunk pointer make it to __free_hook and overwrite to system free it |