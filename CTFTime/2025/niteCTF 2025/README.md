# niteCTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| beating yellow king with musl in ng+ | pwn | `heap` `musl` `fmstr` `fsop` `stderr` `exit` | make all character then use defeat yellow king to leak stack and libc. then use again defeat yellow king to overwrite the stderr file to our fake fsop, lastly choose return and trigger exit |
| NiteBus | pwn | `aarch64 ` `fmstr` `syscall` `execve` | use diagnosic to leak stack address then overwrite the return address at main and use it to do rop chain to execve syscall. after that just overwrite 2 byte at nitebus_server return address to skip some byte |
