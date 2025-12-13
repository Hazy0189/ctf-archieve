#!/bin/bash

gef \
    -ex 'set arch i386:x86-64' \
    -ex 'target remote localhost:1234'\
    -ex 'ks-apply' \
    -ex 'add-symbol-file pwnme.ko 0xffffffffa0000000' 
    # use kmod or `cat /proc/self/modules` to find the base address of the module


