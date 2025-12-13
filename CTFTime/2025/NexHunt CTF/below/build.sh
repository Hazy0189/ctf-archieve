#!/bin/bash

gcc exploit.c -o exploit --static

FILE=initramfs
DIR=/tmp/mnt
# If rootfs.cpio
# Check if /mnt is empty

if [ -z "$(ls -A $DIR)" ]; then
  echo "[*] $DIR is empty. Extracting rootfs..."
  cp "$FILE.cpio" $DIR/
  cd $DIR || exit 1
  # gzip -d "$FILE.cpio.gz"
  cpio -idv < "$FILE.cpio"
else
  echo "[*] $DIR not empty. Updating rootfs..."
  mv exploit $DIR/
  cd $DIR || exit 1
  rm -f "$FILE.cpio"
  find . | cpio -o -H newc > "$FILE.cpio"
fi

# If rootfs.ext3 or rootfs.ext4 or rootfs.img
# mount "$FILE.ext3" $DIR
# mv exploit $DIR/
# chmod +x $DIR/exploit
# umount $DIR

# If rootfs.qcow2
# sudo guestmount -a "$FILE.qcow2" -i --rw $DIR
# sudo mv exploit $DIR/.
# sudo guestunmount $DIR
