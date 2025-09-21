# WatCTF F25

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| hex-editor-xtended-v2 | pwn | `mem` | open /proc/self/mem and overwrite the blacklist string  to others after that just open /secret.txt and read the flag |
| person-tracker | pwn | `heap` `one null byte overflow` | make fake next pointer to the flag address then overwrite it the last byte chunk pointer with nullbyte hopefully point to chunk with flag address |