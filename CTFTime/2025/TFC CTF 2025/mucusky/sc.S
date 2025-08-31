    .text
    .global _start
_start:
    lrw     r0, binsh      # a0 = "/bin/sh"
    movi    r1, 0          # a1 = NULL
    movi    r2, 0          # a2 = NULL
    lrw     r7, 221        # __NR_execve (asm-generic)
    trap    0              # syscall

binsh:
    .ascii  "/bin/sh\0"
