# TJCTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| buggy | pwn | `stack` `fmstr` `ret2shellcode` | leak rbp to get ret address then overwrite the ret address to input buffer + 8. after that give shellcode at input buffer + 8 once and exit |
| linked | pwn | `stack` `GOT` `heap` `restricted` | overwrite cur->next to got puts + 1 (to bypass the null byte). then overwrite got puts to system  so that when exit it cat flag.txt |
| double nested | web | `XSS` `CSP` `SOP` `restricted` | bypass the re with 3 param (a=1&b=2&x=) then xss with iframe data base64 to satisfy the xss filter and csp. for getting the url path where the flag is, redirect to webhook site + document.referer with window top location href |