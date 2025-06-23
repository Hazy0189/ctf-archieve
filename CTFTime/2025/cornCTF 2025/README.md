# cornCTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| poisoned bank | pwn | `stack` `heap` `off by one byte` `restricted` `uaf` `tcache poison` | allocate and free the first and 2 chunks to leak the heap and libc base. use a uaf with max size allocation + 1 to cause a one-byte overflow and corrupt the next chunk’s size. with only 4 chunk slots, perform tcache poisoning to control the fd pointer. free the poisoned chunk to leak a stack address, then poison again to overwrite the return address and get a shell. |