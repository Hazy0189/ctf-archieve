# Neurogrid CTF: Human-Only

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Rice Field | pwn | `very easy` `heap` `ret2shellcode` | use collect rice to increse the rice then call cook rice to get shellcode with short execve bytes. |
| Whisper Vault | pwn | `easy` `stack` `bof` `ret2syscall` `execve` | use the gets to bof then write string to bss with mov qword ptr, after that just do syscall execve with rop chain |
| Gemsmith | pwn | `medium` `heap` `restricted` `double free` `stdout` `exit` `fsop` | since its use libc 2.27, its possible to double free. Do free 3 times then allocate chunk for valid unsorted bins, after that make the second pointer to the chunk and allocate fake chunk size to free it after. After getting libc, target stdout exit fsop to get shell |
| Mantra | pwn | `hard` `heap` `www` `restricted` `exit` |  |