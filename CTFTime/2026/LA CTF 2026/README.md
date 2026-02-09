# LA CTF 2026

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| tcademy | pwn | `heap` `heap overflow` `fsop` `stdout` `restricted` | there is a heap overflow in read_data_into_note function. use it to make fake chunk size so that when free big size to unsorted size valid to get libc address. then do tcache poisoning to IO stderr and  fsop exit. |
| adventure | pwn | `stack` `bof` `pivot` `ret2system` `restricted` | init_board function generate the board by main address byte and check password has bof. move all around the board to leak the main address, then grab and bof use the move_player printf to leak libc address. after that store ret2system in history and grab to bof again to pivot history. |
| ourukla | pwn | `heap` `misalign chunk` `double free` `fsop exit` `stderr` `restricted` | the remove_student doesn't null sinfo pointer causing double free. add and fill student info 8 times then free it to get unsorted bins, after that add student without aux some to make it goes to unsorted bins. then use other index that sinfo pointer in unsorted bins. free it and overflow to overwrite the tcache pointer to stderr then fsop exit. |