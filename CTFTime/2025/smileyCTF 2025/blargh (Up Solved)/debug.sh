#!/bin/bash

qemu-system-x86_64 \
    -m 128M \
    -cpu kvm64,+smep,+smap \
    -kernel bzImage \
    -initrd mnt/initramfs.cpio \
    -snapshot \
    -nographic \
    -monitor /dev/null \
    -no-reboot \
    -append "console=ttyS0 nokaslr kpti=1 quiet panic=0" \
    -s
