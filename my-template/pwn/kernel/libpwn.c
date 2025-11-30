#include "libpwn.h"

#define DEV_PATH "/dev/stagefinal"

int open_device() {
    int fd = open(DEV_PATH, O_RDWR);
    if (fd < 0) error("open");
    return fd;
}