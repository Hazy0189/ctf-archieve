#!/bin/bash

gcc exploit.c -o exploit --static
mv exploit mnt/
cd mnt

rm initramfs.cpio
find . | cpio -o -H newc > initramfs.cpio
cd ..

