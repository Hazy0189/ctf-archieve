# SECCON CTF 14 Quals

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Gachiarray | pwn | `stack` `www` `integer overflow` `got overwrite` `fsop` `stderr` | allocate capacity MAX_INT + 1 and use size 1 then resize it to MAX_INT+1. after that just overwrite got fprintf to gets and fsop to stderr exit|
| Cursed ST | pwn | `heap` `www` `exit` `restricted` | first craft a fake chunk size and use it as the name. use the push operation to allocate memory (malloc) and pop to free it (free). then, fill the tcache to move chunks into the unsorted bins. next, manipulate another chunk to place a table pointer into the unsorted bins. continue freeing chunks until the pointer to the name chunk is freed. allocate memory again to reuse the name chunk, allowing you to overwrite the S table with T. modify the name to target cin good and then overwrite it with cout to leak the libc address. finally, hijack the exit tls dtor to execute arbitrary code and gain a shell |