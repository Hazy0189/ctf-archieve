qemu-system-x86_64 \
	-m 64 \
	-cpu kvm64,+smep\
	-kernel bzImage \
	-append "console=ttyS0 nopti  quiet"  \
	-nographic\
	-monitor /dev/null \
	-initrd initramfs.cpio \
