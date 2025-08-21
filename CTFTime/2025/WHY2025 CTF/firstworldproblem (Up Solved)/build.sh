#!/bin/bash

gcc exploit.c -o exploit --static

FILE=firstworldproblem

# If rootfs.cpio
# Check if /mnt is empty
# if [ -z "$(ls -A /mnt)" ]; then
#   echo "[*] /mnt is empty. Extracting rootfs..."
#   cp "$FILE.cpio.gz" /mnt/
#   cd /mnt || exit 1
#   gzip -d "$FILE.cpio.gz"
#   cpio -idv < "$FILE.cpio"
# else
#   echo "[*] /mnt not empty. Updating rootfs..."
#   mv exploit /mnt/
#   cd /mnt || exit 1
#   rm -f "$FILE.cpio"
#   find . | cpio -o -H newc > "$FILE.cpio"
# fi

# If rootfs.ext3
# mount "$FILE.ext3" mnt
# mv exploit mnt/
# chmod +x mnt/exploit
# umount mnt

# If rootfs.qcow2
sudo guestmount -a "$FILE.qcow2" -i --rw /mnt
sudo mv exploit /mnt/.
sudo guestunmount /mnt
