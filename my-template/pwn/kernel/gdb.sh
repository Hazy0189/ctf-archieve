#!/bin/bash

gef \
    -ex 'set arch i386:x86-64' \
    -ex 'target remote localhost:1234'\
    -ex 'ks-apply' \
    # -ex 'add-symbol-file vuln.ko 0xffffffffc0400000'
# use kmod or `cat /proc/self/modules` to find the base address of the module


