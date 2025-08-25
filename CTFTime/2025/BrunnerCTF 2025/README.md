# BrunnerCTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| Recipe Storage | pwn | `heap` `fsop` `one byte overflow` | Leak heap & libc then overwrite the next chunk to bigger size and allocate to get overlapping chunk. after that just make fake fp and target _IO_list_all to exit. |
| Obligatory Heap | pwn | `stack` `fsop` `stack pivot` | allocate high idx then sort to get leak then sorted again so that it pivot to our input. for some reason there is misalignement issue so using gets stdout then call exit to gain shell |