#!/bin/bash

gcc exploit.c -o exploit --static

# If rootfs.cpio
mv exploit /mnt/
cd /mnt
rm rootfs.cpio
find . | cpio -o -H newc > rootfs.cpio

# If rootfs.ext3
# mount rootfs.ext3 mnt
# mv exploit mnt/
# chmod +x mnt/exploit
# umount mnt

# If rootfs.qcow2
# sudo guestmount -a rootfs.qcow2 -i --rw /mnt
# sudo mv exploit /mnt/.
# sudo guestunmount /mnt