#!/bin/bash

qemu-system-x86_64 \
    -m 64M \
    -kernel ./bzImage \
    -initrd mount/initramfs.cpio \
    -append "console=ttyS0 oops=panic panic=1 quiet loglevel=3 kpti=off kaslr" \
    -nographic \
    -no-reboot \
    -monitor /dev/null
