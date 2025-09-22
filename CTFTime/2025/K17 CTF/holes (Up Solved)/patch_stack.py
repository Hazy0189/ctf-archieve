#!/usr/bin/env python3
# patch_gnu_stack_elftools.py
# Usage: python3 patch_gnu_stack_elftools.py ./binary
# Shows program headers, finds PT_GNU_STACK (if any), and patches ONE byte OR 0x1
# (creates a .bak first). Uses pyelftools for robust parsing.

import sys, shutil, os
from elftools.elf.elffile import ELFFile

if len(sys.argv) != 2:
    print("Usage: python3 patch_gnu_stack_elftools.py ./binary")
    sys.exit(1)

path = sys.argv[1]
if not os.path.isfile(path):
    print("File not found:", path); sys.exit(1)

bak = path + '.bak'
shutil.copy(path, bak)
print("[*] backup created:", bak)

with open(path, 'rb') as f:
    elf = ELFFile(f)

    # basic info
    print("[*] ELF class:", "ELF64" if elf.elfclass == 64 else "ELF32")
    print("[*] little endian:", elf.little_endian)
    print("[*] e_phoff =", hex(elf['e_phoff']), "e_phentsize =", elf['e_phentsize'])
    print()

    # enumerate program headers and print details
    print("Program headers (index: type, offset, filesz, flags):")
    ph_index = None
    for idx, seg in enumerate(elf.iter_segments()):
        p_type = seg.header['p_type']
        p_offset = seg.header['p_offset']
        p_filesz = seg.header['p_filesz']
        p_flags = seg.header.get('p_flags', 0)
        print(f"  [{idx}] {p_type}  offset={hex(p_offset)}  filesz={hex(p_filesz)}  flags=0x{p_flags:x}")
        # Try different ways to detect GNU_STACK:
        if (isinstance(p_type, str) and ('GNU_STACK' in p_type)) or (str(p_type).upper().find('GNU_STACK') != -1):
            ph_index = idx
            ph_seg = seg

    # If not found by string, try scanning section names / raw headers for GNU_STACK token
    if ph_index is None:
        # fallback: sometimes p_type is numeric; check the readelf-like text
        # We'll re-check by comparing the segment bytes to the string "GNU_STACK" in the program header area (best-effort)
        # (But usually the above is enough.)
        print("\n[-] PT_GNU_STACK not detected by pyelftools iteration.")
        print("    If readelf -l ./binary shows a GNU_STACK line, paste it here; otherwise this binary likely has no PT_GNU_STACK.")
        sys.exit(1)

    print(f"\n[*] Found PT_GNU_STACK at program header index {ph_index}.")
    # compute file offset of p_flags in program header table:
    e_phoff = elf['e_phoff']
    e_phentsize = elf['e_phentsize']
    if elf.elfclass == 64:
        p_flags_offset_in_ph = 4
    else:
        p_flags_offset_in_ph = 24
    file_offset = e_phoff + ph_index * e_phentsize + p_flags_offset_in_ph
    print("[*] p_flags start (file offset) =", hex(file_offset))

    # choose target byte depending on endianness
    if elf.little_endian:
        target_offset = file_offset      # low byte is first
    else:
        target_offset = file_offset + 3  # big-endian: low byte is last of 4

print("\n[*] patching file at single byte offset:", hex(target_offset))
with open(path, "r+b") as fh:
    fh.seek(target_offset)
    old = fh.read(1)
    if not old:
        print("[-] failed to read byte at", hex(target_offset)); sys.exit(1)
    old_val = old[0]
    new_val = old_val | 0x1
    if new_val == old_val:
        print("[*] PF_X already set (byte = 0x%02x). No write needed." % old_val)
        sys.exit(0)
    fh.seek(target_offset)
    fh.write(bytes([new_val]))
    fh.flush(); os.fsync(fh.fileno())
    print("[+] wrote one byte: 0x%02x -> 0x%02x at %s" % (old_val, new_val, hex(target_offset)))

print("[*] Done. Backup was:", bak)
