# WHY2025 CTF

| Challenge | Category | Tag | Description | 
| --- | :---: | :---: | --- |
| FirstWorldProblem | pwn | `kernel` `fmstr` `modprobe` | using %i times offset then %px to leak kernel address. after leaking using %pfw to control RIP and increse the modprobe_path value to /tmp then just do modprobe attack to get root. |
| Simple AI Bot | pwn | `stack` `fmstr` `blind` | for this challenges just dump the binary from the remote with format strings then reverse it and you will see the flag. |
| somkracht65537 | crypto | `rsa` `egcd` | since we have diffrent e but the same c and n, we can just use egcd to recover the flag. |

