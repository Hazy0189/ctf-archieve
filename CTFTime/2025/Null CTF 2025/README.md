# Null CTF 2025

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| reloc8 | pwn | `v8` `oob` `toctou` | create fake obj with valueOf is use fpr toctou and use it to achieve oob write the element and length then build addrOf and fakeObj primitives, create arbitrary read/write, obtain an RWX region from a WebAssembly instance and inject execute shellcode |