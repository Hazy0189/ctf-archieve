# NahamCon CTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| The Jumps | pwn | `kernel` `bof` `stack` `modprobe` | When open the proc, there is a stack buffer overflow in the write function. We can leak the kernel address and the canary with read then write to control the rip. After control the rip use gadget like mov qword ptr to write the modprobe_path and do modprobe attack to get the flag. |
