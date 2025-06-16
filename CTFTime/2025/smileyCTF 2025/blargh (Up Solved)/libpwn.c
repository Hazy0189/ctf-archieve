#include "libpwn.h"

#define DEVICE_PATH "/dev/blargh"
#define BLARGH_IOCTL_CODE 0x40086721

int blargh_open() {
    fd = open(DEVICE_PATH, O_RDONLY);
    printf("%d\n", fd);
    if (fd < 0) error("Failed to open device");
    else return fd;
}

int blargh_ioctl(uint64_t arg3) {
    int ret = ioctl(fd, BLARGH_IOCTL_CODE, (void *)arg3 - 0xffffffff81303260);
    if (ret == -1) error("ioctl failed");
    else return ret;
}

void blargh_close() {
    close(fd);
}
