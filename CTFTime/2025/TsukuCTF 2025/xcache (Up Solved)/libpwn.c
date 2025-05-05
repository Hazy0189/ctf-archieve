#include "libpwn.h"
#define DEV_PATH "/dev/vuln"
#define CMD_ALLOC   0xf000
#define CMD_WRITE   0xf001
#define CMD_FREE    0xf002


int fd, seq_fd[0x20];

typedef struct {
  int id;
  size_t size;
  char *data;
} request_t;

void obj_alloc(int id)
{
  request_t req = {.id = id};
  if (ioctl(fd, CMD_ALLOC, &req) == -1) error("ALLOC failed");
  else printf("[+] Obj Alloc 0x200\n");
}

void obj_free(int id) {
  request_t req = {.id = id};
  if (ioctl(fd, CMD_FREE, &req) == -1) error("FREE failed");
  else printf("[+] Obj Free %d\n", id);
}

void obj_write(int id, char *data, size_t size)
{
  request_t req = {.id = id, .size = size, .data = data};
  if (ioctl(fd, CMD_WRITE, &req) == -1) error("WRITE failed");
  else printf("[+] Obj Write %d %p\n", size, data);
}