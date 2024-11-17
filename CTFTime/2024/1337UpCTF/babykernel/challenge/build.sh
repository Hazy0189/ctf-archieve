#!/bin/bash

gcc -static exploit.c -o exploit
mv exploit mount/
cd mount

rm initramfs.cpio
find . | cpio -o -H newc > initramfs.cpio
cd ..

