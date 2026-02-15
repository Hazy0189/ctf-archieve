# 0xFUN CTF 2026

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| 67 | pwn | `heap` `house of botcake` `fsop` `_IO_list_all` | there is no null after free notes in delete_note function. allocate  big size and small size and free to leak heap and libc. then do house of botcake to _IO_list_all and change it to fsop heap and call exit to get shell. |
| 67 revenge | pwn | `heap` `off by null byte` `unsafe unlink` `seccomp` `restricted` | there is off by null byte in edit, do unsafe unlink with size 0x500 and use it to do heap overflow target stderr exit fsop calling gets by setcontext, then do orw to flag.txt to get the flag. |
| chaos | pwn | `vm` `oob` | hex input is decoded into a 3-byte-step VM with an XOR key; abuse the write primitive with a negative offset to overwrite the global dispatch table, then trigger an indirect call (dispatch 0/6) to jump or call system by pointing rdi at a string stored in the bytecode buffer. |
| phantom | pwn | `kernel` `uaf` `mmap` `pagetable` `modprobe_path` | kernel module allocs a page and exposes it via `mmap`, `CMD_FREE` frees the page but the user mapping stays valid (stale mapping UAF). Reclaim the freed page as a userspace PTE page, then rewrite PTEs to map arbitrary PFNs and scan physical memory for `modprobe_path`; overwrite it to a user-controlled helper path and trigger modprobe to drop a root shell |
