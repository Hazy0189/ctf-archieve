#!/bin/sh
qemu-system-x86_64 \
    -m 256M \
    -kernel ./bzImage \
    -initrd /tmp/mnt/initramfs.cpio \
    -append "console=ttyS0 oops=panic panic=1 quiet kaslr" \
    -cpu qemu64,+smep,+smap \
    -monitor /dev/null \
    -nographic \
    -no-reboot \
    -s
