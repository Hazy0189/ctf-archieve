#!/bin/sh
qemu-system-x86_64 \
    -m 64M \
    -cpu qemu64 \
    -kernel bzImage \
    -drive file=rootfs.ext3,format=raw \
    -drive file=flag.txt,format=raw \
    -snapshot \
    -nographic \
    -monitor /dev/null \
    -no-reboot \
    -smp 1 \
    -append "root=/dev/sda rw init=/init console=ttyS0 nokaslr nopti loglevel=0 oops=panic panic=-1"
