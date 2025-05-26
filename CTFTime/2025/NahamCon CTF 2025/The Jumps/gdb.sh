gdb-gef \
	-ex 'set arch i386:x86-64' \
    -ex 'target remote localhost:1234'
	-ex 'file vmlinux' \
    -ex 'ks-apply'
