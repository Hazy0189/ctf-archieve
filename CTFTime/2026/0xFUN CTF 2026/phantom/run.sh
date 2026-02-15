#!/bin/sh
qemu-system-x86_64 \
    -m 256M \
    -kernel ./bzImage \
    -initrd ./initramfs.cpio.gz \
    -append "console=ttyS0 oops=panic panic=1 quiet kaslr" \
    -cpu qemu64,+smep,+smap \
    -monitor /dev/null \
    -nographic \
    -no-reboot
