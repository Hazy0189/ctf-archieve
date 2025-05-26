#include "libpwn.h"
#define DEV_PATH "/proc/shellcode_device"
#define CMD   0x7301

void proc_ioctl()
{
  if (ioctl(fd, CMD, NULL) == -1) error("IOCTL failed");
  else printf("[+] IOCTL work\n");
}

