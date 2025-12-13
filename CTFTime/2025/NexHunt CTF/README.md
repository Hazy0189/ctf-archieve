# NexHunt CTF

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| below | pwn | `kernel` `heap` `modprobe` `poisoning` | use read to leak kernel address then overwrite the free pointer with write and make it to modprobe after that use open 2 times to allocate and overwrite it to do modprobe_path |
| VowBreaker | pwn | `v8` `type confusion` | there is a type confusion in AsyncIteratorPrototypeAsyncDispose() use it to make n array length oob then just make primitive addrOf, fakeObj to get arb write and read after that just overwrite the wasm and execute shellcode |