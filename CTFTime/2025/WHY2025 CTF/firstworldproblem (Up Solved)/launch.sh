#!/bin/bash

qemu-system-x86_64 \
    -cpu kvm64,smep,smap \
    -m 512 \
    -nic user,hostfwd=tcp::1337-:22 \
    -hda firstworldproblem.qcow2 \
    -nographic \
    -monitor none \
    -s
#    -S

