#!/bin/sh

gdb-multiarch mips -ex "set architecture mips:isa32r2" \
    -ex "set disassembly-flavor intel" \
    -ex "set sysroot '/home/kali/Windows/BYUCTF 2025/mips/ctf'" \
    -ex "init-gef" \
    -ex "target remote :1234"
