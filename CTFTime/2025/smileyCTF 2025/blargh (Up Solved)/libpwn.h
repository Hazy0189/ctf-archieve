// inspired by the goat: https://github.com/n132/libx/blob/main/libx.c
#define _GNU_SOURCE
#ifndef LIBPWN_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sched.h>
#include <sys/mman.h>
#include <signal.h>
#include <sys/syscall.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <poll.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdint.h>
#include <errno.h>
#include <stddef.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <assert.h>
#include <sys/timerfd.h>
#include <sys/resource.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <netinet/tcp.h>  // for SOL_TCP, TCP options
#include <sys/prctl.h>
#include <poll.h>
#include <sys/shm.h>

size_t kernel_base = 0xffffffff81000000;
int fd;

#define KADDR(addr) ((size_t)(addr)-0xffffffff81000000 + kernel_base);

typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
size_t modprobe_path, leak;
size_t user_cs, user_ss, user_rflags, user_sp, user_rip;


void spawn_shell() {
    puts("[*] Hello from user land!");
    uid_t uid = getuid();
    if (uid == 0) {
        printf("[+] UID: %d, got root!\n", uid);
        char *args[] = {"/bin/sh", NULL};
        char *env[] = {NULL};
        execve("/bin/sh", args, env); // Directly execute a shell
        perror("execve failed"); // If execve fails, print error
    } else {
        printf("[!] UID: %d, we root-less :(!\n", uid);
        exit(-1);
    }
}

void save_state() {
    __asm__(".intel_syntax noprefix;"
            "mov user_cs, cs;"
            "mov user_ss, ss;"
            "mov user_sp, rsp;"
            "pushf;"
            "pop user_rflags;"
            ".att_syntax");
    user_rip = (size_t)spawn_shell;
    puts("[+] Saved state");
}

void dump_hex(char *buf, size_t size){
 for(int i = 0; i < size/8; i++){
        printf("[+] %d - 0x%016lx\n", i, ((unsigned long *)buf)[i]);
  }
}


void ppause(){
    puts("enter to unpause");
    getchar();
}

void info(const char *msg, unsigned long val){
    printf("[INFO] %s: %p\n", msg, val);
}

void error(const char *msg){
    printf("[ERROR] %s\n", msg);
    exit(-1);
}


#endif /* LIBPWN_H */
