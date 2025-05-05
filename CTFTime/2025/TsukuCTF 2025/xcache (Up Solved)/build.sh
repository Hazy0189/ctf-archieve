#!/bin/bash

gcc -o exploit -static -masm=intel exploit.c
sudo mount rootfs.ext3 mnt
sudo cp exploit mnt/
sudo chmod +x mnt/exploit
sudo umount mnt
