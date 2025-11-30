# LakeCTF Quals 25-26

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Unlink This| pwn | `heap` `heap overflow` `restricted` | leak heap and elf address via overwrite next size larger so that when unlink leak the next and prev address. after that target the crypto struct in heap by making fake next and prev in the crypto heap then do unlink to get libc address. lastly overwrite the crypto struct pointer in elf address to our fake crypto struct and make it to bof via read gadget |