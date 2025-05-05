# TsukuCTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| easy kernel | pwn | `kernel` `heap` `seq_op` `coomit cred` | using the fact after alloc 0x20 open /proc/self/stat (alloc 0x20) then overwrite the op start and trigger it to get RIP |
