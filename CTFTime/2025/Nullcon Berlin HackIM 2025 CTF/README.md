# Nullcon Berlin HackIM 2025 CTF

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Fotispy 3 | pwn | `heap` `oob` | use open file to make libc and heap address in the heap then write and readfile to leak elf address. after that just overwrite the song pointer to got and overwrite realpath to system and open file /bin/sh to get shell |
| Fotispy 4 | pwn | `heap` `unsafe unlink` `one byte overflow` | leak libc with unsortedbins and heap with overwrite header chunk. then do unsafe unlink and target the chunk pointer in elf. after that just change pointer to got free and overwrite it to system then free chunk contain /bin/sh string |
| Fotispy 5 | pwn | `heap` `malloc_hook` `heap overflow` | make missalignment chunk with fastbin dup to point to unsortedbins chunk 3 byte after then free unsortedbins and leak libc byte. after that just target the malloc_hook with fasbin dup and overwrite it to one gadgets |
| Fotispy 7 | pwn | `heap` `unsafe unlink` `heap overflow` `one null byte overflow` `stderr` | use playlist chunk to leak libc with debug function then use unsafe unlink to get overlapping chunk. after that just do tcache poisoning to _IO_2_1_stderr_ and overwrite it to fsop then exit |