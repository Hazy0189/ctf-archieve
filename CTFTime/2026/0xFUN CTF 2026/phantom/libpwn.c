#include "libpwn.h"
#include "interface.h"

#define DEV_PATH "/dev/phantom"
#define PHANTOM_MAP_SIZE 0x1000

int open_device() {
    int fd = open(DEV_PATH, O_RDWR);
    if (fd < 0) error("open");
    return fd;
}

int phantom_alloc(int fd) {
    int ret = ioctl(fd, CMD_ALLOC, 0);
    if (ret < 0) error("ioctl(CMD_ALLOC)");
    return ret;
}

int phantom_free(int fd) {
    int ret = ioctl(fd, CMD_FREE, 0);
    if (ret < 0) error("ioctl(CMD_FREE)");
    return ret;
}

void *phantom_map(int fd) {
    void *p = mmap(NULL, PHANTOM_MAP_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) error("mmap");
    return p;
}

void phantom_unmap(void *p) {
    if (munmap(p, PHANTOM_MAP_SIZE) != 0) error("munmap");
}
