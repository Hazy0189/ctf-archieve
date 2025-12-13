#include "libpwn.h"

#define DEV_PATH "/dev/pwnme"

// Opens the device file and returns the file descriptor
int pwnme_open() {
    int fd = open(DEV_PATH, O_RDWR);
    if (fd < 0) {
       error("Failed to open device");
    }
    return fd;
}

// Writes data to the device
ssize_t pwnme_write(int fd, const char *data, size_t size) {
    ssize_t bytes_written = write(fd, data, size);
    if (bytes_written < 0) {
        error("Failed to write to device");
    }
    return bytes_written;
}

// Reads data from the device
ssize_t pwnme_read(int fd, char *buffer, size_t size) {
    ssize_t bytes_read = read(fd, buffer, size);
    if (bytes_read < 0) {
        error("Failed to read from device");
    }
    return bytes_read;
}

// Closes the device file
void pwnme_close(int fd) {
    if (close(fd) < 0) {
        error("Failed to close device");
    }
}
