# CTF Challenge Index

A navigable index built from each `YEAR/CTF/**/README.md` challenge table. Use the broad **Category** sections or the more specific **Technique / Tag** sections (for example, [`heap`](#tag-heap)). Challenge names link to the source CTF README.

Equivalent source tags are merged under one canonical name in this index; the original event README files are left unchanged.

**Coverage:** 160 challenges across 3 years and 71 CTF events.

## Quick Navigation

- [Browse by year and CTF](#browse-by-year-and-ctf)
- [Browse by category](#browse-by-category)
- [Browse by technique / tag](#browse-by-technique-tag)
- [Tag aliases](#tag-aliases)

### Categories

[`crypto` (4)](#category-crypto) · [`pwn` (151)](#category-pwn) · [`web` (5)](#category-web)

<a id="technique-tag-navigation"></a>
### Techniques / Tags

**3** — [`32bit` (2)](#tag-32bit)

**A** — [`aar` (1)](#tag-aar) · [`aarch64` (2)](#tag-aarch64)

**B** — [`blind` (1)](#tag-blind) · [`bof` (9)](#tag-bof) · [`brute force` (3)](#tag-brute-force)

**C** — [`calloc` (1)](#tag-calloc) · [`canary` (13)](#tag-canary) · [`cmd injection` (1)](#tag-cmd-injection) · [`commit_creds` (2)](#tag-commit-creds) · [`cred` (1)](#tag-cred) · [`cross cache attack` (2)](#tag-cross-cache-attack) · [`crud` (3)](#tag-crud) · [`csp` (1)](#tag-csp)

**D** — [`double free` (1)](#tag-double-free) · [`dynstr` (1)](#tag-dynstr)

**E** — [`egcd` (1)](#tag-egcd) · [`em_csky` (1)](#tag-em-csky) · [`environ` (2)](#tag-environ) · [`execve` (2)](#tag-execve) · [`exit` (5)](#tag-exit)

**F** — [`fastbin` (1)](#tag-fastbin) · [`fclose` (1)](#tag-fclose) · [`flip bit` (1)](#tag-flip-bit) · [`fmtstr` (27)](#tag-fmtstr) · [`fprintf` (1)](#tag-fprintf) · [`fread` (1)](#tag-fread) · [`fsop` (17)](#tag-fsop) · [`fsop exit` (1)](#tag-fsop-exit)

**G** — [`gdb` (1)](#tag-gdb) · [`gef` (1)](#tag-gef) · [`getdents` (1)](#tag-getdents) · [`golang` (1)](#tag-golang) · [`got` (8)](#tag-got)

**H** — [`heap` (53)](#tag-heap) · [`heap overflow` (10)](#tag-heap-overflow) · [`house of botcake` (3)](#tag-house-of-botcake) · [`house of orange` (1)](#tag-house-of-orange) · [`house of plastic cake` (1)](#tag-house-of-plastic-cake)

**I** — [`integer overflow` (5)](#tag-integer-overflow) · [`integer underflow` (1)](#tag-integer-underflow)

**J** — [`jwt` (2)](#tag-jwt)

**K** — [`kernel` (10)](#tag-kernel)

**L** — [`logic error` (5)](#tag-logic-error)

**M** — [`malloc_hook` (1)](#tag-malloc-hook) · [`mangle` (1)](#tag-mangle) · [`mem` (1)](#tag-mem) · [`mips` (1)](#tag-mips) · [`misalign chunk` (1)](#tag-misalign-chunk) · [`mmap` (1)](#tag-mmap) · [`modprobe_path` (4)](#tag-modprobe-path) · [`musl` (1)](#tag-musl)

**O** — [`off-by-one overflow` (11)](#tag-off-by-one-overflow) · [`one gadget` (1)](#tag-one-gadget) · [`oob` (11)](#tag-oob) · [`orw` (7)](#tag-orw) · [`overflow` (1)](#tag-overflow) · [`overwrite` (6)](#tag-overwrite)

**P** — [`page jacking` (1)](#tag-page-jacking) · [`pagetable` (1)](#tag-pagetable) · [`patching` (1)](#tag-patching) · [`pie` (2)](#tag-pie) · [`pipe buffer` (1)](#tag-pipe-buffer) · [`pivot` (1)](#tag-pivot) · [`poisoning` (1)](#tag-poisoning) · [`ptmx` (1)](#tag-ptmx) · [`ptrace` (1)](#tag-ptrace) · [`putchar` (1)](#tag-putchar)

**R** — [`restricted` (34)](#tag-restricted) · [`ret2csu` (1)](#tag-ret2csu) · [`ret2gets` (2)](#tag-ret2gets) · [`ret2libc` (10)](#tag-ret2libc) · [`ret2shellcode` (4)](#tag-ret2shellcode) · [`ret2system` (5)](#tag-ret2system) · [`ret2win` (15)](#tag-ret2win) · [`rsa` (3)](#tag-rsa) · [`rust` (1)](#tag-rust)

**S** — [`scanf` (1)](#tag-scanf) · [`seccomp` (7)](#tag-seccomp) · [`seq_op` (2)](#tag-seq-op) · [`shellcode` (5)](#tag-shellcode) · [`socket` (2)](#tag-socket) · [`sop` (1)](#tag-sop) · [`srand` (3)](#tag-srand) · [`srop` (6)](#tag-srop) · [`stack` (95)](#tag-stack) · [`stack pivot` (5)](#tag-stack-pivot) · [`stderr` (7)](#tag-stderr) · [`stdout` (10)](#tag-stdout) · [`syscall` (3)](#tag-syscall)

**T** — [`tcache poison` (1)](#tag-tcache-poison) · [`toctou` (1)](#tag-toctou) · [`type confusion` (1)](#tag-type-confusion)

**U** — [`uaf` (4)](#tag-uaf) · [`unsafe unlink` (7)](#tag-unsafe-unlink) · [`unsorted bins attack` (1)](#tag-unsorted-bins-attack) · [`upx` (1)](#tag-upx)

**V** — [`v8` (4)](#tag-v8) · [`vm` (1)](#tag-vm)

**W** — [`www` (6)](#tag-www) · [`www2` (1)](#tag-www2) · [`www2exec` (1)](#tag-www2exec)

**X** — [`xss` (1)](#tag-xss)

**#** — [`__free_hook` (4)](#tag-free-hook) · [`_io_list_all` (1)](#tag-io-list-all)

### Tag Aliases

| Canonical tag | Merged source tags |
| --- | --- |
| `__free_hook` | `__free_hook`, `_free_hook`, `free hook`, `freehook` |
| `brute force` | `brute force`, `bruteforce` |
| `commit_creds` | `commit`, `commit cred`, `commit creds`, `coomit cred` |
| `fmtstr` | `fmstr`, `fmtstr` |
| `got` | `got`, `got overwrite` |
| `modprobe_path` | `modprobe`, `modprobe_path`, `modprobepath` |
| `off-by-one overflow` | `off by null byte`, `off by nullbyte`, `off by one`, `off by one byte`, `off by one null byte`, `one byte overflow`, `one null byte`, `one null byte overflow` |
| `seq_op` | `seq op`, `seq_op` |

---

## Browse by Year and CTF

### 2026

2 CTF events · 7 challenges

- [0xFUN CTF 2026](2026/0xFUN%20CTF%202026/README.md) — 4 challenges
- [LA CTF 2026](2026/LA%20CTF%202026/README.md) — 3 challenges

### 2025

55 CTF events · 110 challenges

- [b01lers CTF 2025](2025/b01lers%20CTF%202025/README.md) — 2 challenges
- [BackdoorCTF 2025](2025/BackdoorCTF%202025/README.md) — 4 challenges
- [BITSCTF 2025](2025/BITSCTF%202025/README.md) — 1 challenge
- [BlackHat MEA CTF Qualification 2025](2025/BlackHat%20MEA%20CTF%20Qualification%202025/README.md) — 2 challenges
- [BlitzCTF](2025/BlitzCTF/README.md) — 1 challenge
- [BrunnerCTF 2025](2025/BrunnerCTF%202025/README.md) — 2 challenges
- [BuckeyeCTF 2025](2025/BuckeyeCTF%202025/README.md) — 2 challenges
- [BYUCTF 2025](2025/BYUCTF%202025/README.md) — 3 challenges
- [cornCTF 2025](2025/cornCTF%202025/README.md) — 1 challenge
- [CPCTF 2025](2025/CPCTF%202025/README.md) — 1 challenge
- [CrewCTF 2025](2025/CrewCTF%202025/README.md) — 1 challenge
- [Cyber Apocalypse CTF 2025 Tales from Eldoria](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) — 6 challenges
- [DawgCTF 2025](2025/DawgCTF%202025/README.md) — 1 challenge
- [Dreamhack CTF Season 7 Round #2 (Div. 2)](2025/Dreamhack%20CTF%20Season%207%20Round%20%232%20%28Div.%202%29/README.md) — 3 challenges
- [EHAX CTF 2025](2025/EHAX%20CTF%202025/README.md) — 1 challenge
- [Infobahn CTF 2025](2025/Infobahn%20CTF%202025/README.md) — 2 challenges
- [Iran Tech Olympics CTF 2025](2025/Iran%20Tech%20Olympics%20CTF%202025/README.md) — 2 challenges
- [K!nd4SUS CTF 2025](2025/K%21nd4SUS%20CTF%202025/README.md) — 2 challenges
- [K17 CTF](2025/K17%20CTF/README.md) — 2 challenges
- [KalmarCTF 2025](2025/KalmarCTF%202025/README.md) — 1 challenge
- [LA CTF 2025](2025/LA%20CTF%202025/README.md) — 1 challenge
- [LakeCTF Quals 25-26](2025/LakeCTF%20Quals%2025-26/README.md) — 1 challenge
- [LINE CTF 2025](2025/LINE%20CTF%202025/README.md) — 1 challenge
- [LIT CTF 2025](2025/LIT%20CTF%202025/README.md) — 3 challenges
- [N0PSctf](2025/N0PSctf/README.md) — 2 challenges
- [NahamCon CTF 2025](2025/NahamCon%20CTF%202025/README.md) — 1 challenge
- [NexHunt CTF](2025/NexHunt%20CTF/README.md) — 2 challenges
- [niteCTF 2025](2025/niteCTF%202025/README.md) — 2 challenges
- [Null CTF 2025](2025/Null%20CTF%202025/README.md) — 1 challenge
- [Nullcon Berlin HackIM 2025 CTF](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) — 4 challenges
- [Nullcon Goa HackIM 2025 CTF](2025/Nullcon%20Goa%20HackIM%202025%20CTF/README.md) — 3 challenges
- [Pearl CTF](2025/Pearl%20CTF/README.md) — 1 challenge
- [Pragyan CTF 2025](2025/Pragyan%20CTF%202025/README.md) — 4 challenges
- [PwnMe CTF Quals 2025](2025/PwnMe%20CTF%20Quals%202025/README.md) — 2 challenges
- [QnQSec CTF 2025](2025/QnQSec%20CTF%202025/README.md) — 2 challenges
- [RITSEC CTF 2025](2025/RITSEC%20CTF%202025/README.md) — 3 challenges
- [RSTCON 2025 CTF](2025/RSTCON%202025%20CTF/README.md) — 1 challenge
- [SECCON CTF 14 Quals](2025/SECCON%20CTF%2014%20Quals/README.md) — 2 challenges
- [Securinets CTF Quals 2025](2025/Securinets%20CTF%20Quals%202025/README.md) — 1 challenge
- [smileyCTF 2025](2025/smileyCTF%202025/README.md) — 3 challenges
- [StackSmash CTF](2025/StackSmash%20CTF/README.md) — 4 challenges
- [SwampCTF 2025](2025/SwampCTF%202025/README.md) — 1 challenge
- [TFC CTF 2025](2025/TFC%20CTF%202025/README.md) — 1 challenge
- [TJCTF 2025](2025/TJCTF%202025/README.md) — 3 challenges
- [TPCTF 2025](2025/TPCTF%202025/README.md) — 1 challenge
- [TRX CTF 2025](2025/TRX%20CTF%202025/README.md) — 3 challenges
- [TSCCTF 2025](2025/TSCCTF%202025/noview%20%28Up%20Solved%29/README.md) — 1 challenge
- [TsukuCTF 2025](2025/TsukuCTF%202025/README.md) — 3 challenges
- [UIUCTF 2025](2025/UIUCTF%202025/README.md) — 1 challenge
- [UMDCTF 2025](2025/UMDCTF%202025/README.md) — 1 challenge
- [VuwCTF 2025](2025/VuwCTF%202025/README.md) — 2 challenges
- [WatCTF F25](2025/WatCTF%20F25/README.md) — 2 challenges
- [WHY2025 CTF](2025/WHY2025%20CTF/README.md) — 3 challenges
- [WolvCTF 2025](2025/WolvCTF%202025/README.md) — 2 challenges
- [World Wide CTF 2025](2025/World%20Wide%20CTF%202025/README.md) — 2 challenges

### 2024

14 CTF events · 43 challenges

- [1337UpCTF](2024/1337UpCTF/README.md) — 6 challenges
- [Affrica BattleCTF2024](2024/Affrica%20BattleCTF2024/README.md) — 2 challenges
- [BuckeyeCTF 2024](2024/BuckeyeCTF%202024/pwn/README.md) — 6 challenges
- [H7CTF 2024](2024/H7CTF%202024/README.md) — 3 challenges
- [HeroCTFv6](2024/HeroCTFv6/README.md) — 2 challenges
- [IERAE-CTF 2024](2024/IERAE-CTF%202024/README.md) — 2 challenges
- [IronCTF 2024](2024/IronCTF%202024/README.md) — 1 challenge
- [niteCTF 2024](2024/niteCTF%202024/README.md) — 4 challenges
- [No Hack No CTF 2024](2024/No%20Hack%20No%20CTF%202024/README.md) — 5 challenges
- [PatriotCTF 2024](2024/PatriotCTF%202024/README.md) — 2 challenges
- [THJCC CTF 2024 winter](2024/THJCC%20CTF%202024%20winter/README.md) — 2 challenges
- [UrmiaCTF 2024](2024/UrmiaCTF%202024/README.md) — 3 challenges
- [USCCTF 2024](2024/USCCTF%202024/README.md) — 4 challenges
- [Wargames.MY CTF 2024](2024/Wargames.MY%20CTF%202024/README.md) — 1 challenge

---

## Browse by Category

<a id="category-crypto"></a>
### crypto (4)

| Challenge | Year | CTF | Tags |
| --- | :---: | --- | --- |
| [Affe!n](2025/Dreamhack%20CTF%20Season%207%20Round%20%232%20%28Div.%202%29/README.md) | 2025 | Dreamhack CTF Season 7 Round #2 (Div. 2) | `brute force` |
| [somkracht65537](2025/WHY2025%20CTF/README.md) | 2025 | WHY2025 CTF | `rsa` `egcd` |
| [OG Fermat](2024/H7CTF%202024/README.md) | 2024 | H7CTF 2024 | `rsa` |
| [Rasa](2024/UrmiaCTF%202024/README.md) | 2024 | UrmiaCTF 2024 | `rsa` |

[Back to top](#ctf-challenge-index)

<a id="category-pwn"></a>
### pwn (151)

| Challenge | Year | CTF | Tags |
| --- | :---: | --- | --- |
| [67](2026/0xFUN%20CTF%202026/README.md) | 2026 | 0xFUN CTF 2026 | `heap` `house of botcake` `fsop` `_io_list_all` |
| [67 revenge](2026/0xFUN%20CTF%202026/README.md) | 2026 | 0xFUN CTF 2026 | `heap` `off-by-one overflow` `unsafe unlink` `seccomp` `restricted` |
| [chaos](2026/0xFUN%20CTF%202026/README.md) | 2026 | 0xFUN CTF 2026 | `vm` `oob` |
| [phantom](2026/0xFUN%20CTF%202026/README.md) | 2026 | 0xFUN CTF 2026 | `kernel` `uaf` `mmap` `pagetable` `modprobe_path` |
| [adventure](2026/LA%20CTF%202026/README.md) | 2026 | LA CTF 2026 | `stack` `bof` `pivot` `ret2system` `restricted` |
| [ourukla](2026/LA%20CTF%202026/README.md) | 2026 | LA CTF 2026 | `heap` `misalign chunk` `double free` `fsop exit` `stderr` `restricted` |
| [tcademy](2026/LA%20CTF%202026/README.md) | 2026 | LA CTF 2026 | `heap` `heap overflow` `fsop` `stdout` `restricted` |
| [guessguesswhosstack](2025/b01lers%20CTF%202025/README.md) | 2025 | b01lers CTF 2025 | `stack` `www2` `fmtstr` `exit` |
| [scanner](2025/b01lers%20CTF%202025/README.md) | 2025 | b01lers CTF 2025 | `stack` `fmtstr` `scanf` `stdout` |
| [Gamble](2025/BackdoorCTF%202025/README.md) | 2025 | BackdoorCTF 2025 | `stack` `srand` `fmtstr` `bof` `restricted` |
| [Lolimancer](2025/BackdoorCTF%202025/README.md) | 2025 | BackdoorCTF 2025 | `stack` `fmtstr` `bof` `canary` |
| [Santa's Workshop](2025/BackdoorCTF%202025/README.md) | 2025 | BackdoorCTF 2025 | `heap` `off-by-one overflow` `unsafe unlink` |
| [The Last Duel](2025/BackdoorCTF%202025/README.md) | 2025 | BackdoorCTF 2025 | `heap` `off-by-one overflow` `exit` `stderr` `fsop` `restricted` |
| [BabyPWN](2025/BITSCTF%202025/README.md) | 2025 | BITSCTF 2025 | `stack` `shellcode` |
| [calc](2025/BlackHat%20MEA%20CTF%20Qualification%202025/README.md) | 2025 | BlackHat MEA CTF Qualification 2025 | `heap` `oob` |
| [File101](2025/BlackHat%20MEA%20CTF%20Qualification%202025/README.md) | 2025 | BlackHat MEA CTF Qualification 2025 | `stack` `fsop` `stdout` `stderr` `restricted` |
| [Safe Note](2025/BlitzCTF/README.md) | 2025 | BlitzCTF | `heap` `stack` `unsafe unlink` `seccomp` `orw` `off-by-one overflow` `restricted` |
| [Obligatory Heap](2025/BrunnerCTF%202025/README.md) | 2025 | BrunnerCTF 2025 | `stack` `fsop` `stack pivot` |
| [Recipe Storage](2025/BrunnerCTF%202025/README.md) | 2025 | BrunnerCTF 2025 | `heap` `fsop` `off-by-one overflow` |
| [Guessing Game](2025/BuckeyeCTF%202025/README.md) | 2025 | BuckeyeCTF 2025 | `stack` `brute force` `canary` `ret2libc` |
| [iloverust](2025/BuckeyeCTF%202025/README.md) | 2025 | BuckeyeCTF 2025 | `heap` `oob` `house of botcake` `got` |
| [Game of Yap](2025/BYUCTF%202025/README.md) | 2025 | BYUCTF 2025 | `stack` `putchar` `ret2system` |
| [Goat](2025/BYUCTF%202025/README.md) | 2025 | BYUCTF 2025 | `stack` `got` `fmtstr` |
| [MIPS](2025/BYUCTF%202025/README.md) | 2025 | BYUCTF 2025 | `mips` `bof` `canary` `ret2win` |
| [poisoned bank](2025/cornCTF%202025/README.md) | 2025 | cornCTF 2025 | `stack` `heap` `off-by-one overflow` `restricted` `uaf` `tcache poison` |
| [tasks](2025/CPCTF%202025/README.md) | 2025 | CPCTF 2025 | `stack` |
| [heeap banging](2025/CrewCTF%202025/README.md) | 2025 | CrewCTF 2025 | `heap` `crud` `calloc` `fastbin` `heap overflow` `__free_hook` `restricted` |
| [Blessing](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria | `stack` |
| [Contractor](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria | `stack` `overflow` `ret2win` |
| [Crossbow](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria | `stack` `orw` |
| [Laconic](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria | `stack` `srop` |
| [Quack quack](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria | `stack` `canary` `ret2win` |
| [Strategist](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria | `heap` `restricted` `heap overflow` `__free_hook` |
| [Clobber](2025/DawgCTF%202025/README.md) | 2025 | DawgCTF 2025 | `stack` `ret2gets` |
| [xrop](2025/Dreamhack%20CTF%20Season%207%20Round%20%232%20%28Div.%202%29/README.md) | 2025 | Dreamhack CTF Season 7 Round #2 (Div. 2) | `stack` `canary` `ret2libc` `fmtstr` |
| [Cash Memo](2025/EHAX%20CTF%202025/README.md) | 2025 | EHAX CTF 2025 | `heap` `stack` `environ` |
| [pwn a brainrot](2025/Infobahn%20CTF%202025/README.md) | 2025 | Infobahn CTF 2025 | `rust` `oob` `www` |
| [The Butterfly Effect](2025/Infobahn%20CTF%202025/README.md) | 2025 | Infobahn CTF 2025 | `v8` `off-by-one overflow` `flip bit` |
| [account management](2025/Iran%20Tech%20Olympics%20CTF%202025/README.md) | 2025 | Iran Tech Olympics CTF 2025 | `heap` `uaf` `getdents` `orw` `seccomp` `restricted` |
| [pearls](2025/Iran%20Tech%20Olympics%20CTF%202025/README.md) | 2025 | Iran Tech Olympics CTF 2025 | `stack` `ret2gets` |
| [En(d)less behaviour](2025/K%21nd4SUS%20CTF%202025/README.md) | 2025 | K!nd4SUS CTF 2025 | `stack` `fmtstr` `restricted` `integer overflow` |
| [Vector Madness](2025/K%21nd4SUS%20CTF%202025/README.md) | 2025 | K!nd4SUS CTF 2025 | `stack` `heap` `oob` `seccomp` `orw` |
| [holes](2025/K17%20CTF/README.md) | 2025 | K17 CTF | `stack` `patching` `ret2shellcode` |
| [into the void](2025/K17%20CTF/README.md) | 2025 | K17 CTF | `stack` `bof` `srop` `restricted` |
| [Merger](2025/KalmarCTF%202025/README.md) | 2025 | KalmarCTF 2025 | `heap` `fsop` `stdout` `restricted` |
| [minecraft](2025/LA%20CTF%202025/README.md) | 2025 | LA CTF 2025 | `stack` `stack pivot` `stdout` `got` `restricted` |
| [Unlink This](2025/LakeCTF%20Quals%2025-26/README.md) | 2025 | LakeCTF Quals 25-26 | `heap` `heap overflow` `restricted` |
| [Broken](2025/LINE%20CTF%202025/README.md) | 2025 | LINE CTF 2025 | `stack` `canary` `ret2libc` |
| [no nonsesnse](2025/LIT%20CTF%202025/README.md) | 2025 | LIT CTF 2025 | `stack` `www` `dynstr` |
| [stillestprintf](2025/LIT%20CTF%202025/README.md) | 2025 | LIT CTF 2025 | `stack` `fmtstr` `restricted` |
| [the mound](2025/LIT%20CTF%202025/README.md) | 2025 | LIT CTF 2025 | `stack` `oob` `exit` |
| [pwnfield](2025/N0PSctf/README.md) | 2025 | N0PSctf | `stack` `shellcode` `execve` `restricted` |
| [Under Attack](2025/N0PSctf/README.md) | 2025 | N0PSctf | `stack` `heap` `crud` `ret2system` `restricted` |
| [The Jumps](2025/NahamCon%20CTF%202025/README.md) | 2025 | NahamCon CTF 2025 | `kernel` `bof` `stack` `modprobe_path` |
| [below](2025/NexHunt%20CTF/README.md) | 2025 | NexHunt CTF | `kernel` `heap` `modprobe_path` `poisoning` |
| [VowBreaker](2025/NexHunt%20CTF/README.md) | 2025 | NexHunt CTF | `v8` `type confusion` |
| [beating yellow king with musl in ng+](2025/niteCTF%202025/README.md) | 2025 | niteCTF 2025 | `heap` `musl` `fmtstr` `fsop` `stderr` `exit` |
| [NiteBus](2025/niteCTF%202025/README.md) | 2025 | niteCTF 2025 | `aarch64` `fmtstr` `syscall` `execve` |
| [reloc8](2025/Null%20CTF%202025/README.md) | 2025 | Null CTF 2025 | `v8` `oob` `toctou` |
| [Fotispy 3](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | 2025 | Nullcon Berlin HackIM 2025 CTF | `heap` `oob` |
| [Fotispy 4](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | 2025 | Nullcon Berlin HackIM 2025 CTF | `heap` `unsafe unlink` `off-by-one overflow` |
| [Fotispy 5](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | 2025 | Nullcon Berlin HackIM 2025 CTF | `heap` `malloc_hook` `heap overflow` |
| [Fotispy 7](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | 2025 | Nullcon Berlin HackIM 2025 CTF | `heap` `unsafe unlink` `heap overflow` `off-by-one overflow` `stderr` |
| [hateful](2025/Nullcon%20Goa%20HackIM%202025%20CTF/README.md) | 2025 | Nullcon Goa HackIM 2025 CTF | `stack` `fmtstr` `ret2libc` |
| [hateful2](2025/Nullcon%20Goa%20HackIM%202025%20CTF/README.md) | 2025 | Nullcon Goa HackIM 2025 CTF | `heap` `fsop` `stdout` |
| [Mr Unlucky](2025/Nullcon%20Goa%20HackIM%202025%20CTF/README.md) | 2025 | Nullcon Goa HackIM 2025 CTF | `stack` `srand` |
| [Mr. %ROPOT%](2025/Pearl%20CTF/README.md) | 2025 | Pearl CTF | `stack` `fmtstr` `ret2libc` |
| [Dupocalypse](2025/Pragyan%20CTF%202025/README.md) | 2025 | Pragyan CTF 2025 | `stack` `socket` `ret2csu` `stack pivot` |
| [Intresting](2025/Pragyan%20CTF%202025/README.md) | 2025 | Pragyan CTF 2025 | `stack` `upx` `ret2libc` `canary` `fmtstr` |
| [Size Doesn't Matter](2025/Pragyan%20CTF%202025/README.md) | 2025 | Pragyan CTF 2025 | `stack` `syscall` `srop` |
| [The Heap of the Brave](2025/Pragyan%20CTF%202025/README.md) | 2025 | Pragyan CTF 2025 | `heap` `overwrite` |
| [Eistein](2025/PwnMe%20CTF%20Quals%202025/README.md) | 2025 | PwnMe CTF Quals 2025 | `stack` `www2exec` `stdout` `one gadget` |
| [NoPrint](2025/PwnMe%20CTF%20Quals%202025/README.md) | 2025 | PwnMe CTF Quals 2025 | `stack` `fmtstr` `restricted` `fprintf` |
| [malloc wrapper part 1](2025/QnQSec%20CTF%202025/README.md) | 2025 | QnQSec CTF 2025 | `stack` `heap` `integer overflow` `oob` |
| [notez](2025/QnQSec%20CTF%202025/README.md) | 2025 | QnQSec CTF 2025 | `stack` `bof` `srop` `restricted` |
| [Bit Burger](2025/RITSEC%20CTF%202025/README.md) | 2025 | RITSEC CTF 2025 | `stack` |
| [Hashmatch](2025/RITSEC%20CTF%202025/README.md) | 2025 | RITSEC CTF 2025 | `stack` `ret2system` `fmtstr` |
| [StarShip Registration](2025/RITSEC%20CTF%202025/README.md) | 2025 | RITSEC CTF 2025 | `stack` `golang` |
| [optimization](2025/RSTCON%202025%20CTF/README.md) | 2025 | RSTCON 2025 CTF | `v8` `oob` |
| [Cursed ST](2025/SECCON%20CTF%2014%20Quals/README.md) | 2025 | SECCON CTF 14 Quals | `heap` `www` `exit` `restricted` |
| [Gachiarray](2025/SECCON%20CTF%2014%20Quals/README.md) | 2025 | SECCON CTF 14 Quals | `stack` `www` `integer overflow` `got` `fsop` `stderr` |
| [V-tables](2025/Securinets%20CTF%20Quals%202025/README.md) | 2025 | Securinets CTF Quals 2025 | `stack` `fsop` |
| [blargh](2025/smileyCTF%202025/README.md) | 2025 | smileyCTF 2025 | `kernel` `stack` `cred` `aar` |
| [debuggable3](2025/smileyCTF%202025/README.md) | 2025 | smileyCTF 2025 | `gdb` `gef` |
| [limit](2025/smileyCTF%202025/README.md) | 2025 | smileyCTF 2025 | `heap` `fsop` `stdout` `unsafe unlink` `crud` `restricted` |
| [Its A Me Jumpio](2025/StackSmash%20CTF/README.md) | 2025 | StackSmash CTF | `stack` `integer underflow` |
| [Jumpio Love Letter](2025/StackSmash%20CTF/README.md) | 2025 | StackSmash CTF | `heap` `fmtstr` `heap overflow` `fsop` `fclose` |
| [Refreshments](2025/StackSmash%20CTF/README.md) | 2025 | StackSmash CTF | `heap` `unsorted bins attack` `house of orange` `restricted` `off-by-one overflow` |
| [Super Jumpio Kart](2025/StackSmash%20CTF/README.md) | 2025 | StackSmash CTF | `stack` `canary` `fmtstr` `ret2system` `bof` |
| [Notecard](2025/SwampCTF%202025/README.md) | 2025 | SwampCTF 2025 | `heap` `oob` `got` |
| [mucusky](2025/TFC%20CTF%202025/README.md) | 2025 | TFC CTF 2025 | `stack` `em_csky` `ret2shellcode` |
| [buggy](2025/TJCTF%202025/README.md) | 2025 | TJCTF 2025 | `stack` `fmtstr` `ret2shellcode` |
| [linked](2025/TJCTF%202025/README.md) | 2025 | TJCTF 2025 | `stack` `got` `heap` `restricted` |
| [EzDB](2025/TPCTF%202025/README.md) | 2025 | TPCTF 2025 | `heap` `heap overflow` `fsop` `stderr` `restricted` |
| [Canon Event](2025/TRX%20CTF%202025/README.md) | 2025 | TRX CTF 2025 | `stack` `ptrace` `ret2shellcode` `seccomp` `orw` |
| [Free The Monster](2025/TRX%20CTF%202025/README.md) | 2025 | TRX CTF 2025 | `heap` `stack` `environ` `ret2libc` `restricted` `house of botcake` |
| [Virtual Insanity](2025/TRX%20CTF%202025/README.md) | 2025 | TRX CTF 2025 | `stack` `ret2win` `pie` `restricted` |
| [no view](2025/TSCCTF%202025/noview%20%28Up%20Solved%29/README.md) | 2025 | TSCCTF 2025 | `heap` `fsop` `stdout` `house of plastic cake` |
| [easy kernel](2025/TsukuCTF%202025/README.md) | 2025 | TsukuCTF 2025 | `kernel` `heap` `seq_op` `commit_creds` |
| [new era](2025/TsukuCTF%202025/README.md) | 2025 | TsukuCTF 2025 | `kernel` `heap` `pipe buffer` `page jacking` `cross cache attack` |
| [xcache](2025/TsukuCTF%202025/README.md) | 2025 | TsukuCTF 2025 | `kernel` `heap` `seq_op` `cross cache attack` |
| [Baby Kernel](2025/UIUCTF%202025/README.md) | 2025 | UIUCTF 2025 | `kernel` `heap` `stack pivot` `uaf` `commit_creds` `ptmx` |
| [one write](2025/UMDCTF%202025/README.md) | 2025 | UMDCTF 2025 | `heap` `stack` `got` `unsafe unlink` `heap overflow` |
| [Idempotence](2025/VuwCTF%202025/README.md) | 2025 | VuwCTF 2025 | `heap` `restricted` |
| [Kiwiphone](2025/VuwCTF%202025/README.md) | 2025 | VuwCTF 2025 | `stack` `www` |
| [hex-editor-xtended-v2](2025/WatCTF%20F25/README.md) | 2025 | WatCTF F25 | `mem` |
| [person-tracker](2025/WatCTF%20F25/README.md) | 2025 | WatCTF F25 | `heap` `off-by-one overflow` |
| [FirstWorldProblem](2025/WHY2025%20CTF/README.md) | 2025 | WHY2025 CTF | `kernel` `fmtstr` `modprobe_path` |
| [Simple AI Bot](2025/WHY2025%20CTF/README.md) | 2025 | WHY2025 CTF | `stack` `fmtstr` `blind` |
| [DryWall](2025/WolvCTF%202025/README.md) | 2025 | WolvCTF 2025 | `stack` `seccomp` `orw` |
| [Take Note](2025/WolvCTF%202025/README.md) | 2025 | WolvCTF 2025 | `heap` `fmtstr` `www` `fsop` |
| [Arm World](2025/World%20Wide%20CTF%202025/README.md) | 2025 | World Wide CTF 2025 | `aarch64` `bof` |
| [Giggity Ropity Goo](2025/World%20Wide%20CTF%202025/README.md) | 2025 | World Wide CTF 2025 | `stack` `stack pivot` `srop` `got` `restricted` |
| [Baby Kernel](2024/1337UpCTF/README.md) | 2024 | 1337UpCTF | `kernel` `stack` |
| [Floormat Mega Sale](2024/1337UpCTF/README.md) | 2024 | 1337UpCTF | `fmtstr` `stack` |
| [Notepad](2024/1337UpCTF/README.md) | 2024 | 1337UpCTF | `heap` |
| [Retro2Win](2024/1337UpCTF/README.md) | 2024 | 1337UpCTF | `stack` `ret2win` |
| [Rigged Slot Machine 2](2024/1337UpCTF/README.md) | 2024 | 1337UpCTF | `stack` `overwrite` |
| [UAP](2024/1337UpCTF/README.md) | 2024 | 1337UpCTF | `heap` `overwrite` |
| [NTcrack](2024/Affrica%20BattleCTF2024/README.md) | 2024 | Affrica BattleCTF2024 | `stack` `fmtstr` `ret2libc` |
| [Sweet Game](2024/Affrica%20BattleCTF2024/README.md) | 2024 | Affrica BattleCTF2024 | `stack` `srand` `shellcode` `seccomp` |
| [calc](2024/BuckeyeCTF%202024/pwn/README.md) | 2024 | BuckeyeCTF 2024 | `integer overflow` `stack` `canary` `ret2win` |
| [color](2024/BuckeyeCTF%202024/pwn/README.md) | 2024 | BuckeyeCTF 2024 | `stack` `overwrite` |
| [runaway0](2024/BuckeyeCTF%202024/pwn/README.md) | 2024 | BuckeyeCTF 2024 | `stack` |
| [runaway1](2024/BuckeyeCTF%202024/pwn/README.md) | 2024 | BuckeyeCTF 2024 | `stack` `ret2win` `32bit` |
| [runaway2](2024/BuckeyeCTF%202024/pwn/README.md) | 2024 | BuckeyeCTF 2024 | `stack` `ret2win` |
| [runaway3](2024/BuckeyeCTF%202024/pwn/README.md) | 2024 | BuckeyeCTF 2024 | `stack` `ret2win` |
| [Crack](2024/H7CTF%202024/README.md) | 2024 | H7CTF 2024 | `stack` `ret2win` |
| [Questionaire](2024/H7CTF%202024/README.md) | 2024 | H7CTF 2024 | `stack` `fmtstr` |
| [Bankrupt](2024/HeroCTFv6/README.md) | 2024 | HeroCTFv6 | `stack` `logic error` |
| [HeapPie](2024/HeroCTFv6/README.md) | 2024 | HeroCTFv6 | `heap` `overwrite` |
| [Copy & Waste](2024/IERAE-CTF%202024/README.md) | 2024 | IERAE-CTF 2024 | `stack` `logic error` |
| [This is a warmup](2024/IERAE-CTF%202024/README.md) | 2024 | IERAE-CTF 2024 | `stack` `integer overflow` |
| [SimpleNotes](2024/IronCTF%202024/README.md) | 2024 | IronCTF 2024 | `heap` `__free_hook` |
| [Chaterine](2024/niteCTF%202024/README.md) | 2024 | niteCTF 2024 | `heap` `mangle` `fmtstr` |
| [Hook The World](2024/niteCTF%202024/README.md) | 2024 | niteCTF 2024 | `heap` `__free_hook` |
| [Mixed Signals](2024/niteCTF%202024/README.md) | 2024 | niteCTF 2024 | `stack` `syscall` `srop` |
| [Print The Gifts](2024/niteCTF%202024/README.md) | 2024 | niteCTF 2024 | `stack` `fmtstr` `ret2libc` |
| [dof](2024/No%20Hack%20No%20CTF%202024/README.md) | 2024 | No Hack No CTF 2024 | `stack` `overwrite` |
| [filtered](2024/No%20Hack%20No%20CTF%202024/README.md) | 2024 | No Hack No CTF 2024 | `stack` `shellcode` `restricted` |
| [fishbabys library](2024/No%20Hack%20No%20CTF%202024/README.md) | 2024 | No Hack No CTF 2024 | `stack` |
| [grading system](2024/No%20Hack%20No%20CTF%202024/README.md) | 2024 | No Hack No CTF 2024 | `stack` `logic error` |
| [Slime Machine Challenge](2024/No%20Hack%20No%20CTF%202024/README.md) | 2024 | No Hack No CTF 2024 | `heap` `stack` `ret2libc` |
| [Not So Shrimple Is It](2024/PatriotCTF%202024/README.md) | 2024 | PatriotCTF 2024 | `stack` `ret2win` |
| [Infinite Recursion](2024/THJCC%20CTF%202024%20winter/README.md) | 2024 | THJCC CTF 2024 winter | `stack` `ret2win` `fmtstr` |
| [The Best Anime](2024/THJCC%20CTF%202024%20winter/README.md) | 2024 | THJCC CTF 2024 winter | `stack` `canary` `orw` `restricted` |
| [Look Up](2024/UrmiaCTF%202024/README.md) | 2024 | UrmiaCTF 2024 | `stack` `canary` `pie` `ret2win` |
| [Orange](2024/UrmiaCTF%202024/README.md) | 2024 | UrmiaCTF 2024 | `stack` `shellcode` `canary` |
| [Portal](2024/USCCTF%202024/README.md) | 2024 | USCCTF 2024 | `stack` `32bit` `ret2win` |
| [Readers](2024/USCCTF%202024/README.md) | 2024 | USCCTF 2024 | `stack` `canary` `ret2win` `brute force` |
| [screenwriter](2024/Wargames.MY%20CTF%202024/README.md) | 2024 | Wargames.MY CTF 2024 | `heap` `fsop` `fread` `stdout` `heap overflow` |

[Back to top](#ctf-challenge-index)

<a id="category-web"></a>
### web (5)

| Challenge | Year | CTF | Tags |
| --- | :---: | --- | --- |
| [Simple Note Manager](2025/Dreamhack%20CTF%20Season%207%20Round%20%232%20%28Div.%202%29/README.md) | 2025 | Dreamhack CTF Season 7 Round #2 (Div. 2) | `cmd injection` |
| [double nested](2025/TJCTF%202025/README.md) | 2025 | TJCTF 2025 | `xss` `csp` `sop` `restricted` |
| [Impersonate](2024/PatriotCTF%202024/README.md) | 2024 | PatriotCTF 2024 | `jwt` |
| [Tictocket](2024/USCCTF%202024/README.md) | 2024 | USCCTF 2024 | `socket` `logic error` |
| [Tommy's adventure](2024/USCCTF%202024/README.md) | 2024 | USCCTF 2024 | `jwt` `logic error` |

[Back to top](#ctf-challenge-index)

---

<a id="browse-by-technique-tag"></a>
## Browse by Technique / Tag

<a id="tag-32bit"></a>
### `32bit` (2)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [runaway1](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [Portal](2024/USCCTF%202024/README.md) | pwn | 2024 | USCCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-free-hook"></a>
### `__free_hook` (4)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [heeap banging](2025/CrewCTF%202025/README.md) | pwn | 2025 | CrewCTF 2025 |
| [Strategist](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [SimpleNotes](2024/IronCTF%202024/README.md) | pwn | 2024 | IronCTF 2024 |
| [Hook The World](2024/niteCTF%202024/README.md) | pwn | 2024 | niteCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-io-list-all"></a>
### `_io_list_all` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [67](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-aar"></a>
### `aar` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [blargh](2025/smileyCTF%202025/README.md) | pwn | 2025 | smileyCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-aarch64"></a>
### `aarch64` (2)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [NiteBus](2025/niteCTF%202025/README.md) | pwn | 2025 | niteCTF 2025 |
| [Arm World](2025/World%20Wide%20CTF%202025/README.md) | pwn | 2025 | World Wide CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-blind"></a>
### `blind` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Simple AI Bot](2025/WHY2025%20CTF/README.md) | pwn | 2025 | WHY2025 CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-bof"></a>
### `bof` (9)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [adventure](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |
| [Gamble](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [Lolimancer](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [MIPS](2025/BYUCTF%202025/README.md) | pwn | 2025 | BYUCTF 2025 |
| [into the void](2025/K17%20CTF/README.md) | pwn | 2025 | K17 CTF |
| [The Jumps](2025/NahamCon%20CTF%202025/README.md) | pwn | 2025 | NahamCon CTF 2025 |
| [notez](2025/QnQSec%20CTF%202025/README.md) | pwn | 2025 | QnQSec CTF 2025 |
| [Super Jumpio Kart](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |
| [Arm World](2025/World%20Wide%20CTF%202025/README.md) | pwn | 2025 | World Wide CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-brute-force"></a>
### `brute force` (3)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Guessing Game](2025/BuckeyeCTF%202025/README.md) | pwn | 2025 | BuckeyeCTF 2025 |
| [Affe!n](2025/Dreamhack%20CTF%20Season%207%20Round%20%232%20%28Div.%202%29/README.md) | crypto | 2025 | Dreamhack CTF Season 7 Round #2 (Div. 2) |
| [Readers](2024/USCCTF%202024/README.md) | pwn | 2024 | USCCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-calloc"></a>
### `calloc` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [heeap banging](2025/CrewCTF%202025/README.md) | pwn | 2025 | CrewCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-canary"></a>
### `canary` (13)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Lolimancer](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [Guessing Game](2025/BuckeyeCTF%202025/README.md) | pwn | 2025 | BuckeyeCTF 2025 |
| [MIPS](2025/BYUCTF%202025/README.md) | pwn | 2025 | BYUCTF 2025 |
| [Quack quack](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [xrop](2025/Dreamhack%20CTF%20Season%207%20Round%20%232%20%28Div.%202%29/README.md) | pwn | 2025 | Dreamhack CTF Season 7 Round #2 (Div. 2) |
| [Broken](2025/LINE%20CTF%202025/README.md) | pwn | 2025 | LINE CTF 2025 |
| [Intresting](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |
| [Super Jumpio Kart](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |
| [calc](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [The Best Anime](2024/THJCC%20CTF%202024%20winter/README.md) | pwn | 2024 | THJCC CTF 2024 winter |
| [Look Up](2024/UrmiaCTF%202024/README.md) | pwn | 2024 | UrmiaCTF 2024 |
| [Orange](2024/UrmiaCTF%202024/README.md) | pwn | 2024 | UrmiaCTF 2024 |
| [Readers](2024/USCCTF%202024/README.md) | pwn | 2024 | USCCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-cmd-injection"></a>
### `cmd injection` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Simple Note Manager](2025/Dreamhack%20CTF%20Season%207%20Round%20%232%20%28Div.%202%29/README.md) | web | 2025 | Dreamhack CTF Season 7 Round #2 (Div. 2) |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-commit-creds"></a>
### `commit_creds` (2)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [easy kernel](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |
| [Baby Kernel](2025/UIUCTF%202025/README.md) | pwn | 2025 | UIUCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-cred"></a>
### `cred` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [blargh](2025/smileyCTF%202025/README.md) | pwn | 2025 | smileyCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-cross-cache-attack"></a>
### `cross cache attack` (2)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [new era](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |
| [xcache](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-crud"></a>
### `crud` (3)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [heeap banging](2025/CrewCTF%202025/README.md) | pwn | 2025 | CrewCTF 2025 |
| [Under Attack](2025/N0PSctf/README.md) | pwn | 2025 | N0PSctf |
| [limit](2025/smileyCTF%202025/README.md) | pwn | 2025 | smileyCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-csp"></a>
### `csp` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [double nested](2025/TJCTF%202025/README.md) | web | 2025 | TJCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-double-free"></a>
### `double free` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [ourukla](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-dynstr"></a>
### `dynstr` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [no nonsesnse](2025/LIT%20CTF%202025/README.md) | pwn | 2025 | LIT CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-egcd"></a>
### `egcd` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [somkracht65537](2025/WHY2025%20CTF/README.md) | crypto | 2025 | WHY2025 CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-em-csky"></a>
### `em_csky` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [mucusky](2025/TFC%20CTF%202025/README.md) | pwn | 2025 | TFC CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-environ"></a>
### `environ` (2)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Cash Memo](2025/EHAX%20CTF%202025/README.md) | pwn | 2025 | EHAX CTF 2025 |
| [Free The Monster](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-execve"></a>
### `execve` (2)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [pwnfield](2025/N0PSctf/README.md) | pwn | 2025 | N0PSctf |
| [NiteBus](2025/niteCTF%202025/README.md) | pwn | 2025 | niteCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-exit"></a>
### `exit` (5)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [guessguesswhosstack](2025/b01lers%20CTF%202025/README.md) | pwn | 2025 | b01lers CTF 2025 |
| [The Last Duel](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [the mound](2025/LIT%20CTF%202025/README.md) | pwn | 2025 | LIT CTF 2025 |
| [beating yellow king with musl in ng+](2025/niteCTF%202025/README.md) | pwn | 2025 | niteCTF 2025 |
| [Cursed ST](2025/SECCON%20CTF%2014%20Quals/README.md) | pwn | 2025 | SECCON CTF 14 Quals |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-fastbin"></a>
### `fastbin` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [heeap banging](2025/CrewCTF%202025/README.md) | pwn | 2025 | CrewCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-fclose"></a>
### `fclose` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Jumpio Love Letter](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-flip-bit"></a>
### `flip bit` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [The Butterfly Effect](2025/Infobahn%20CTF%202025/README.md) | pwn | 2025 | Infobahn CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-fmtstr"></a>
### `fmtstr` (27)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [guessguesswhosstack](2025/b01lers%20CTF%202025/README.md) | pwn | 2025 | b01lers CTF 2025 |
| [scanner](2025/b01lers%20CTF%202025/README.md) | pwn | 2025 | b01lers CTF 2025 |
| [Gamble](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [Lolimancer](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [Goat](2025/BYUCTF%202025/README.md) | pwn | 2025 | BYUCTF 2025 |
| [xrop](2025/Dreamhack%20CTF%20Season%207%20Round%20%232%20%28Div.%202%29/README.md) | pwn | 2025 | Dreamhack CTF Season 7 Round #2 (Div. 2) |
| [En(d)less behaviour](2025/K%21nd4SUS%20CTF%202025/README.md) | pwn | 2025 | K!nd4SUS CTF 2025 |
| [stillestprintf](2025/LIT%20CTF%202025/README.md) | pwn | 2025 | LIT CTF 2025 |
| [beating yellow king with musl in ng+](2025/niteCTF%202025/README.md) | pwn | 2025 | niteCTF 2025 |
| [NiteBus](2025/niteCTF%202025/README.md) | pwn | 2025 | niteCTF 2025 |
| [hateful](2025/Nullcon%20Goa%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Goa HackIM 2025 CTF |
| [Mr. %ROPOT%](2025/Pearl%20CTF/README.md) | pwn | 2025 | Pearl CTF |
| [Intresting](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |
| [NoPrint](2025/PwnMe%20CTF%20Quals%202025/README.md) | pwn | 2025 | PwnMe CTF Quals 2025 |
| [Hashmatch](2025/RITSEC%20CTF%202025/README.md) | pwn | 2025 | RITSEC CTF 2025 |
| [Jumpio Love Letter](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |
| [Super Jumpio Kart](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |
| [buggy](2025/TJCTF%202025/README.md) | pwn | 2025 | TJCTF 2025 |
| [FirstWorldProblem](2025/WHY2025%20CTF/README.md) | pwn | 2025 | WHY2025 CTF |
| [Simple AI Bot](2025/WHY2025%20CTF/README.md) | pwn | 2025 | WHY2025 CTF |
| [Take Note](2025/WolvCTF%202025/README.md) | pwn | 2025 | WolvCTF 2025 |
| [Floormat Mega Sale](2024/1337UpCTF/README.md) | pwn | 2024 | 1337UpCTF |
| [NTcrack](2024/Affrica%20BattleCTF2024/README.md) | pwn | 2024 | Affrica BattleCTF2024 |
| [Questionaire](2024/H7CTF%202024/README.md) | pwn | 2024 | H7CTF 2024 |
| [Chaterine](2024/niteCTF%202024/README.md) | pwn | 2024 | niteCTF 2024 |
| [Print The Gifts](2024/niteCTF%202024/README.md) | pwn | 2024 | niteCTF 2024 |
| [Infinite Recursion](2024/THJCC%20CTF%202024%20winter/README.md) | pwn | 2024 | THJCC CTF 2024 winter |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-fprintf"></a>
### `fprintf` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [NoPrint](2025/PwnMe%20CTF%20Quals%202025/README.md) | pwn | 2025 | PwnMe CTF Quals 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-fread"></a>
### `fread` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [screenwriter](2024/Wargames.MY%20CTF%202024/README.md) | pwn | 2024 | Wargames.MY CTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-fsop"></a>
### `fsop` (17)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [67](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |
| [tcademy](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |
| [The Last Duel](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [File101](2025/BlackHat%20MEA%20CTF%20Qualification%202025/README.md) | pwn | 2025 | BlackHat MEA CTF Qualification 2025 |
| [Obligatory Heap](2025/BrunnerCTF%202025/README.md) | pwn | 2025 | BrunnerCTF 2025 |
| [Recipe Storage](2025/BrunnerCTF%202025/README.md) | pwn | 2025 | BrunnerCTF 2025 |
| [Merger](2025/KalmarCTF%202025/README.md) | pwn | 2025 | KalmarCTF 2025 |
| [beating yellow king with musl in ng+](2025/niteCTF%202025/README.md) | pwn | 2025 | niteCTF 2025 |
| [hateful2](2025/Nullcon%20Goa%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Goa HackIM 2025 CTF |
| [Gachiarray](2025/SECCON%20CTF%2014%20Quals/README.md) | pwn | 2025 | SECCON CTF 14 Quals |
| [V-tables](2025/Securinets%20CTF%20Quals%202025/README.md) | pwn | 2025 | Securinets CTF Quals 2025 |
| [limit](2025/smileyCTF%202025/README.md) | pwn | 2025 | smileyCTF 2025 |
| [Jumpio Love Letter](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |
| [EzDB](2025/TPCTF%202025/README.md) | pwn | 2025 | TPCTF 2025 |
| [no view](2025/TSCCTF%202025/noview%20%28Up%20Solved%29/README.md) | pwn | 2025 | TSCCTF 2025 |
| [Take Note](2025/WolvCTF%202025/README.md) | pwn | 2025 | WolvCTF 2025 |
| [screenwriter](2024/Wargames.MY%20CTF%202024/README.md) | pwn | 2024 | Wargames.MY CTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-fsop-exit"></a>
### `fsop exit` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [ourukla](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-gdb"></a>
### `gdb` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [debuggable3](2025/smileyCTF%202025/README.md) | pwn | 2025 | smileyCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-gef"></a>
### `gef` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [debuggable3](2025/smileyCTF%202025/README.md) | pwn | 2025 | smileyCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-getdents"></a>
### `getdents` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [account management](2025/Iran%20Tech%20Olympics%20CTF%202025/README.md) | pwn | 2025 | Iran Tech Olympics CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-golang"></a>
### `golang` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [StarShip Registration](2025/RITSEC%20CTF%202025/README.md) | pwn | 2025 | RITSEC CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-got"></a>
### `got` (8)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [iloverust](2025/BuckeyeCTF%202025/README.md) | pwn | 2025 | BuckeyeCTF 2025 |
| [Goat](2025/BYUCTF%202025/README.md) | pwn | 2025 | BYUCTF 2025 |
| [minecraft](2025/LA%20CTF%202025/README.md) | pwn | 2025 | LA CTF 2025 |
| [Gachiarray](2025/SECCON%20CTF%2014%20Quals/README.md) | pwn | 2025 | SECCON CTF 14 Quals |
| [Notecard](2025/SwampCTF%202025/README.md) | pwn | 2025 | SwampCTF 2025 |
| [linked](2025/TJCTF%202025/README.md) | pwn | 2025 | TJCTF 2025 |
| [one write](2025/UMDCTF%202025/README.md) | pwn | 2025 | UMDCTF 2025 |
| [Giggity Ropity Goo](2025/World%20Wide%20CTF%202025/README.md) | pwn | 2025 | World Wide CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-heap"></a>
### `heap` (53)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [67](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |
| [67 revenge](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |
| [ourukla](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |
| [tcademy](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |
| [Santa's Workshop](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [The Last Duel](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [calc](2025/BlackHat%20MEA%20CTF%20Qualification%202025/README.md) | pwn | 2025 | BlackHat MEA CTF Qualification 2025 |
| [Safe Note](2025/BlitzCTF/README.md) | pwn | 2025 | BlitzCTF |
| [Recipe Storage](2025/BrunnerCTF%202025/README.md) | pwn | 2025 | BrunnerCTF 2025 |
| [iloverust](2025/BuckeyeCTF%202025/README.md) | pwn | 2025 | BuckeyeCTF 2025 |
| [poisoned bank](2025/cornCTF%202025/README.md) | pwn | 2025 | cornCTF 2025 |
| [heeap banging](2025/CrewCTF%202025/README.md) | pwn | 2025 | CrewCTF 2025 |
| [Strategist](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [Cash Memo](2025/EHAX%20CTF%202025/README.md) | pwn | 2025 | EHAX CTF 2025 |
| [account management](2025/Iran%20Tech%20Olympics%20CTF%202025/README.md) | pwn | 2025 | Iran Tech Olympics CTF 2025 |
| [Vector Madness](2025/K%21nd4SUS%20CTF%202025/README.md) | pwn | 2025 | K!nd4SUS CTF 2025 |
| [Merger](2025/KalmarCTF%202025/README.md) | pwn | 2025 | KalmarCTF 2025 |
| [Unlink This](2025/LakeCTF%20Quals%2025-26/README.md) | pwn | 2025 | LakeCTF Quals 25-26 |
| [Under Attack](2025/N0PSctf/README.md) | pwn | 2025 | N0PSctf |
| [below](2025/NexHunt%20CTF/README.md) | pwn | 2025 | NexHunt CTF |
| [beating yellow king with musl in ng+](2025/niteCTF%202025/README.md) | pwn | 2025 | niteCTF 2025 |
| [Fotispy 3](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |
| [Fotispy 4](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |
| [Fotispy 5](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |
| [Fotispy 7](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |
| [hateful2](2025/Nullcon%20Goa%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Goa HackIM 2025 CTF |
| [The Heap of the Brave](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |
| [malloc wrapper part 1](2025/QnQSec%20CTF%202025/README.md) | pwn | 2025 | QnQSec CTF 2025 |
| [Cursed ST](2025/SECCON%20CTF%2014%20Quals/README.md) | pwn | 2025 | SECCON CTF 14 Quals |
| [limit](2025/smileyCTF%202025/README.md) | pwn | 2025 | smileyCTF 2025 |
| [Jumpio Love Letter](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |
| [Refreshments](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |
| [Notecard](2025/SwampCTF%202025/README.md) | pwn | 2025 | SwampCTF 2025 |
| [linked](2025/TJCTF%202025/README.md) | pwn | 2025 | TJCTF 2025 |
| [EzDB](2025/TPCTF%202025/README.md) | pwn | 2025 | TPCTF 2025 |
| [Free The Monster](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |
| [no view](2025/TSCCTF%202025/noview%20%28Up%20Solved%29/README.md) | pwn | 2025 | TSCCTF 2025 |
| [easy kernel](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |
| [new era](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |
| [xcache](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |
| [Baby Kernel](2025/UIUCTF%202025/README.md) | pwn | 2025 | UIUCTF 2025 |
| [one write](2025/UMDCTF%202025/README.md) | pwn | 2025 | UMDCTF 2025 |
| [Idempotence](2025/VuwCTF%202025/README.md) | pwn | 2025 | VuwCTF 2025 |
| [person-tracker](2025/WatCTF%20F25/README.md) | pwn | 2025 | WatCTF F25 |
| [Take Note](2025/WolvCTF%202025/README.md) | pwn | 2025 | WolvCTF 2025 |
| [Notepad](2024/1337UpCTF/README.md) | pwn | 2024 | 1337UpCTF |
| [UAP](2024/1337UpCTF/README.md) | pwn | 2024 | 1337UpCTF |
| [HeapPie](2024/HeroCTFv6/README.md) | pwn | 2024 | HeroCTFv6 |
| [SimpleNotes](2024/IronCTF%202024/README.md) | pwn | 2024 | IronCTF 2024 |
| [Chaterine](2024/niteCTF%202024/README.md) | pwn | 2024 | niteCTF 2024 |
| [Hook The World](2024/niteCTF%202024/README.md) | pwn | 2024 | niteCTF 2024 |
| [Slime Machine Challenge](2024/No%20Hack%20No%20CTF%202024/README.md) | pwn | 2024 | No Hack No CTF 2024 |
| [screenwriter](2024/Wargames.MY%20CTF%202024/README.md) | pwn | 2024 | Wargames.MY CTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-heap-overflow"></a>
### `heap overflow` (10)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [tcademy](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |
| [heeap banging](2025/CrewCTF%202025/README.md) | pwn | 2025 | CrewCTF 2025 |
| [Strategist](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [Unlink This](2025/LakeCTF%20Quals%2025-26/README.md) | pwn | 2025 | LakeCTF Quals 25-26 |
| [Fotispy 5](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |
| [Fotispy 7](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |
| [Jumpio Love Letter](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |
| [EzDB](2025/TPCTF%202025/README.md) | pwn | 2025 | TPCTF 2025 |
| [one write](2025/UMDCTF%202025/README.md) | pwn | 2025 | UMDCTF 2025 |
| [screenwriter](2024/Wargames.MY%20CTF%202024/README.md) | pwn | 2024 | Wargames.MY CTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-house-of-botcake"></a>
### `house of botcake` (3)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [67](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |
| [iloverust](2025/BuckeyeCTF%202025/README.md) | pwn | 2025 | BuckeyeCTF 2025 |
| [Free The Monster](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-house-of-orange"></a>
### `house of orange` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Refreshments](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-house-of-plastic-cake"></a>
### `house of plastic cake` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [no view](2025/TSCCTF%202025/noview%20%28Up%20Solved%29/README.md) | pwn | 2025 | TSCCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-integer-overflow"></a>
### `integer overflow` (5)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [En(d)less behaviour](2025/K%21nd4SUS%20CTF%202025/README.md) | pwn | 2025 | K!nd4SUS CTF 2025 |
| [malloc wrapper part 1](2025/QnQSec%20CTF%202025/README.md) | pwn | 2025 | QnQSec CTF 2025 |
| [Gachiarray](2025/SECCON%20CTF%2014%20Quals/README.md) | pwn | 2025 | SECCON CTF 14 Quals |
| [calc](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [This is a warmup](2024/IERAE-CTF%202024/README.md) | pwn | 2024 | IERAE-CTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-integer-underflow"></a>
### `integer underflow` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Its A Me Jumpio](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-jwt"></a>
### `jwt` (2)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Impersonate](2024/PatriotCTF%202024/README.md) | web | 2024 | PatriotCTF 2024 |
| [Tommy's adventure](2024/USCCTF%202024/README.md) | web | 2024 | USCCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-kernel"></a>
### `kernel` (10)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [phantom](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |
| [The Jumps](2025/NahamCon%20CTF%202025/README.md) | pwn | 2025 | NahamCon CTF 2025 |
| [below](2025/NexHunt%20CTF/README.md) | pwn | 2025 | NexHunt CTF |
| [blargh](2025/smileyCTF%202025/README.md) | pwn | 2025 | smileyCTF 2025 |
| [easy kernel](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |
| [new era](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |
| [xcache](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |
| [Baby Kernel](2025/UIUCTF%202025/README.md) | pwn | 2025 | UIUCTF 2025 |
| [FirstWorldProblem](2025/WHY2025%20CTF/README.md) | pwn | 2025 | WHY2025 CTF |
| [Baby Kernel](2024/1337UpCTF/README.md) | pwn | 2024 | 1337UpCTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-logic-error"></a>
### `logic error` (5)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Bankrupt](2024/HeroCTFv6/README.md) | pwn | 2024 | HeroCTFv6 |
| [Copy & Waste](2024/IERAE-CTF%202024/README.md) | pwn | 2024 | IERAE-CTF 2024 |
| [grading system](2024/No%20Hack%20No%20CTF%202024/README.md) | pwn | 2024 | No Hack No CTF 2024 |
| [Tictocket](2024/USCCTF%202024/README.md) | web | 2024 | USCCTF 2024 |
| [Tommy's adventure](2024/USCCTF%202024/README.md) | web | 2024 | USCCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-malloc-hook"></a>
### `malloc_hook` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Fotispy 5](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-mangle"></a>
### `mangle` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Chaterine](2024/niteCTF%202024/README.md) | pwn | 2024 | niteCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-mem"></a>
### `mem` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [hex-editor-xtended-v2](2025/WatCTF%20F25/README.md) | pwn | 2025 | WatCTF F25 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-mips"></a>
### `mips` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [MIPS](2025/BYUCTF%202025/README.md) | pwn | 2025 | BYUCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-misalign-chunk"></a>
### `misalign chunk` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [ourukla](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-mmap"></a>
### `mmap` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [phantom](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-modprobe-path"></a>
### `modprobe_path` (4)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [phantom](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |
| [The Jumps](2025/NahamCon%20CTF%202025/README.md) | pwn | 2025 | NahamCon CTF 2025 |
| [below](2025/NexHunt%20CTF/README.md) | pwn | 2025 | NexHunt CTF |
| [FirstWorldProblem](2025/WHY2025%20CTF/README.md) | pwn | 2025 | WHY2025 CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-musl"></a>
### `musl` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [beating yellow king with musl in ng+](2025/niteCTF%202025/README.md) | pwn | 2025 | niteCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-off-by-one-overflow"></a>
### `off-by-one overflow` (11)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [67 revenge](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |
| [Santa's Workshop](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [The Last Duel](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [Safe Note](2025/BlitzCTF/README.md) | pwn | 2025 | BlitzCTF |
| [Recipe Storage](2025/BrunnerCTF%202025/README.md) | pwn | 2025 | BrunnerCTF 2025 |
| [poisoned bank](2025/cornCTF%202025/README.md) | pwn | 2025 | cornCTF 2025 |
| [The Butterfly Effect](2025/Infobahn%20CTF%202025/README.md) | pwn | 2025 | Infobahn CTF 2025 |
| [Fotispy 4](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |
| [Fotispy 7](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |
| [Refreshments](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |
| [person-tracker](2025/WatCTF%20F25/README.md) | pwn | 2025 | WatCTF F25 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-one-gadget"></a>
### `one gadget` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Eistein](2025/PwnMe%20CTF%20Quals%202025/README.md) | pwn | 2025 | PwnMe CTF Quals 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-oob"></a>
### `oob` (11)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [chaos](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |
| [calc](2025/BlackHat%20MEA%20CTF%20Qualification%202025/README.md) | pwn | 2025 | BlackHat MEA CTF Qualification 2025 |
| [iloverust](2025/BuckeyeCTF%202025/README.md) | pwn | 2025 | BuckeyeCTF 2025 |
| [pwn a brainrot](2025/Infobahn%20CTF%202025/README.md) | pwn | 2025 | Infobahn CTF 2025 |
| [Vector Madness](2025/K%21nd4SUS%20CTF%202025/README.md) | pwn | 2025 | K!nd4SUS CTF 2025 |
| [the mound](2025/LIT%20CTF%202025/README.md) | pwn | 2025 | LIT CTF 2025 |
| [reloc8](2025/Null%20CTF%202025/README.md) | pwn | 2025 | Null CTF 2025 |
| [Fotispy 3](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |
| [malloc wrapper part 1](2025/QnQSec%20CTF%202025/README.md) | pwn | 2025 | QnQSec CTF 2025 |
| [optimization](2025/RSTCON%202025%20CTF/README.md) | pwn | 2025 | RSTCON 2025 CTF |
| [Notecard](2025/SwampCTF%202025/README.md) | pwn | 2025 | SwampCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-orw"></a>
### `orw` (7)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Safe Note](2025/BlitzCTF/README.md) | pwn | 2025 | BlitzCTF |
| [Crossbow](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [account management](2025/Iran%20Tech%20Olympics%20CTF%202025/README.md) | pwn | 2025 | Iran Tech Olympics CTF 2025 |
| [Vector Madness](2025/K%21nd4SUS%20CTF%202025/README.md) | pwn | 2025 | K!nd4SUS CTF 2025 |
| [Canon Event](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |
| [DryWall](2025/WolvCTF%202025/README.md) | pwn | 2025 | WolvCTF 2025 |
| [The Best Anime](2024/THJCC%20CTF%202024%20winter/README.md) | pwn | 2024 | THJCC CTF 2024 winter |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-overflow"></a>
### `overflow` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Contractor](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-overwrite"></a>
### `overwrite` (6)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [The Heap of the Brave](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |
| [Rigged Slot Machine 2](2024/1337UpCTF/README.md) | pwn | 2024 | 1337UpCTF |
| [UAP](2024/1337UpCTF/README.md) | pwn | 2024 | 1337UpCTF |
| [color](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [HeapPie](2024/HeroCTFv6/README.md) | pwn | 2024 | HeroCTFv6 |
| [dof](2024/No%20Hack%20No%20CTF%202024/README.md) | pwn | 2024 | No Hack No CTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-page-jacking"></a>
### `page jacking` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [new era](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-pagetable"></a>
### `pagetable` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [phantom](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-patching"></a>
### `patching` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [holes](2025/K17%20CTF/README.md) | pwn | 2025 | K17 CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-pie"></a>
### `pie` (2)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Virtual Insanity](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |
| [Look Up](2024/UrmiaCTF%202024/README.md) | pwn | 2024 | UrmiaCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-pipe-buffer"></a>
### `pipe buffer` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [new era](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-pivot"></a>
### `pivot` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [adventure](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-poisoning"></a>
### `poisoning` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [below](2025/NexHunt%20CTF/README.md) | pwn | 2025 | NexHunt CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-ptmx"></a>
### `ptmx` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Baby Kernel](2025/UIUCTF%202025/README.md) | pwn | 2025 | UIUCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-ptrace"></a>
### `ptrace` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Canon Event](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-putchar"></a>
### `putchar` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Game of Yap](2025/BYUCTF%202025/README.md) | pwn | 2025 | BYUCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-restricted"></a>
### `restricted` (34)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [67 revenge](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |
| [adventure](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |
| [ourukla](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |
| [tcademy](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |
| [Gamble](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [The Last Duel](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [File101](2025/BlackHat%20MEA%20CTF%20Qualification%202025/README.md) | pwn | 2025 | BlackHat MEA CTF Qualification 2025 |
| [Safe Note](2025/BlitzCTF/README.md) | pwn | 2025 | BlitzCTF |
| [poisoned bank](2025/cornCTF%202025/README.md) | pwn | 2025 | cornCTF 2025 |
| [heeap banging](2025/CrewCTF%202025/README.md) | pwn | 2025 | CrewCTF 2025 |
| [Strategist](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [account management](2025/Iran%20Tech%20Olympics%20CTF%202025/README.md) | pwn | 2025 | Iran Tech Olympics CTF 2025 |
| [En(d)less behaviour](2025/K%21nd4SUS%20CTF%202025/README.md) | pwn | 2025 | K!nd4SUS CTF 2025 |
| [into the void](2025/K17%20CTF/README.md) | pwn | 2025 | K17 CTF |
| [Merger](2025/KalmarCTF%202025/README.md) | pwn | 2025 | KalmarCTF 2025 |
| [minecraft](2025/LA%20CTF%202025/README.md) | pwn | 2025 | LA CTF 2025 |
| [Unlink This](2025/LakeCTF%20Quals%2025-26/README.md) | pwn | 2025 | LakeCTF Quals 25-26 |
| [stillestprintf](2025/LIT%20CTF%202025/README.md) | pwn | 2025 | LIT CTF 2025 |
| [pwnfield](2025/N0PSctf/README.md) | pwn | 2025 | N0PSctf |
| [Under Attack](2025/N0PSctf/README.md) | pwn | 2025 | N0PSctf |
| [NoPrint](2025/PwnMe%20CTF%20Quals%202025/README.md) | pwn | 2025 | PwnMe CTF Quals 2025 |
| [notez](2025/QnQSec%20CTF%202025/README.md) | pwn | 2025 | QnQSec CTF 2025 |
| [Cursed ST](2025/SECCON%20CTF%2014%20Quals/README.md) | pwn | 2025 | SECCON CTF 14 Quals |
| [limit](2025/smileyCTF%202025/README.md) | pwn | 2025 | smileyCTF 2025 |
| [Refreshments](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |
| [double nested](2025/TJCTF%202025/README.md) | web | 2025 | TJCTF 2025 |
| [linked](2025/TJCTF%202025/README.md) | pwn | 2025 | TJCTF 2025 |
| [EzDB](2025/TPCTF%202025/README.md) | pwn | 2025 | TPCTF 2025 |
| [Free The Monster](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |
| [Virtual Insanity](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |
| [Idempotence](2025/VuwCTF%202025/README.md) | pwn | 2025 | VuwCTF 2025 |
| [Giggity Ropity Goo](2025/World%20Wide%20CTF%202025/README.md) | pwn | 2025 | World Wide CTF 2025 |
| [filtered](2024/No%20Hack%20No%20CTF%202024/README.md) | pwn | 2024 | No Hack No CTF 2024 |
| [The Best Anime](2024/THJCC%20CTF%202024%20winter/README.md) | pwn | 2024 | THJCC CTF 2024 winter |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-ret2csu"></a>
### `ret2csu` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Dupocalypse](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-ret2gets"></a>
### `ret2gets` (2)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Clobber](2025/DawgCTF%202025/README.md) | pwn | 2025 | DawgCTF 2025 |
| [pearls](2025/Iran%20Tech%20Olympics%20CTF%202025/README.md) | pwn | 2025 | Iran Tech Olympics CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-ret2libc"></a>
### `ret2libc` (10)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Guessing Game](2025/BuckeyeCTF%202025/README.md) | pwn | 2025 | BuckeyeCTF 2025 |
| [xrop](2025/Dreamhack%20CTF%20Season%207%20Round%20%232%20%28Div.%202%29/README.md) | pwn | 2025 | Dreamhack CTF Season 7 Round #2 (Div. 2) |
| [Broken](2025/LINE%20CTF%202025/README.md) | pwn | 2025 | LINE CTF 2025 |
| [hateful](2025/Nullcon%20Goa%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Goa HackIM 2025 CTF |
| [Mr. %ROPOT%](2025/Pearl%20CTF/README.md) | pwn | 2025 | Pearl CTF |
| [Intresting](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |
| [Free The Monster](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |
| [NTcrack](2024/Affrica%20BattleCTF2024/README.md) | pwn | 2024 | Affrica BattleCTF2024 |
| [Print The Gifts](2024/niteCTF%202024/README.md) | pwn | 2024 | niteCTF 2024 |
| [Slime Machine Challenge](2024/No%20Hack%20No%20CTF%202024/README.md) | pwn | 2024 | No Hack No CTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-ret2shellcode"></a>
### `ret2shellcode` (4)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [holes](2025/K17%20CTF/README.md) | pwn | 2025 | K17 CTF |
| [mucusky](2025/TFC%20CTF%202025/README.md) | pwn | 2025 | TFC CTF 2025 |
| [buggy](2025/TJCTF%202025/README.md) | pwn | 2025 | TJCTF 2025 |
| [Canon Event](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-ret2system"></a>
### `ret2system` (5)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [adventure](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |
| [Game of Yap](2025/BYUCTF%202025/README.md) | pwn | 2025 | BYUCTF 2025 |
| [Under Attack](2025/N0PSctf/README.md) | pwn | 2025 | N0PSctf |
| [Hashmatch](2025/RITSEC%20CTF%202025/README.md) | pwn | 2025 | RITSEC CTF 2025 |
| [Super Jumpio Kart](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-ret2win"></a>
### `ret2win` (15)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [MIPS](2025/BYUCTF%202025/README.md) | pwn | 2025 | BYUCTF 2025 |
| [Contractor](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [Quack quack](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [Virtual Insanity](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |
| [Retro2Win](2024/1337UpCTF/README.md) | pwn | 2024 | 1337UpCTF |
| [calc](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [runaway1](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [runaway2](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [runaway3](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [Crack](2024/H7CTF%202024/README.md) | pwn | 2024 | H7CTF 2024 |
| [Not So Shrimple Is It](2024/PatriotCTF%202024/README.md) | pwn | 2024 | PatriotCTF 2024 |
| [Infinite Recursion](2024/THJCC%20CTF%202024%20winter/README.md) | pwn | 2024 | THJCC CTF 2024 winter |
| [Look Up](2024/UrmiaCTF%202024/README.md) | pwn | 2024 | UrmiaCTF 2024 |
| [Portal](2024/USCCTF%202024/README.md) | pwn | 2024 | USCCTF 2024 |
| [Readers](2024/USCCTF%202024/README.md) | pwn | 2024 | USCCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-rsa"></a>
### `rsa` (3)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [somkracht65537](2025/WHY2025%20CTF/README.md) | crypto | 2025 | WHY2025 CTF |
| [OG Fermat](2024/H7CTF%202024/README.md) | crypto | 2024 | H7CTF 2024 |
| [Rasa](2024/UrmiaCTF%202024/README.md) | crypto | 2024 | UrmiaCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-rust"></a>
### `rust` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [pwn a brainrot](2025/Infobahn%20CTF%202025/README.md) | pwn | 2025 | Infobahn CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-scanf"></a>
### `scanf` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [scanner](2025/b01lers%20CTF%202025/README.md) | pwn | 2025 | b01lers CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-seccomp"></a>
### `seccomp` (7)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [67 revenge](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |
| [Safe Note](2025/BlitzCTF/README.md) | pwn | 2025 | BlitzCTF |
| [account management](2025/Iran%20Tech%20Olympics%20CTF%202025/README.md) | pwn | 2025 | Iran Tech Olympics CTF 2025 |
| [Vector Madness](2025/K%21nd4SUS%20CTF%202025/README.md) | pwn | 2025 | K!nd4SUS CTF 2025 |
| [Canon Event](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |
| [DryWall](2025/WolvCTF%202025/README.md) | pwn | 2025 | WolvCTF 2025 |
| [Sweet Game](2024/Affrica%20BattleCTF2024/README.md) | pwn | 2024 | Affrica BattleCTF2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-seq-op"></a>
### `seq_op` (2)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [easy kernel](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |
| [xcache](2025/TsukuCTF%202025/README.md) | pwn | 2025 | TsukuCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-shellcode"></a>
### `shellcode` (5)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [BabyPWN](2025/BITSCTF%202025/README.md) | pwn | 2025 | BITSCTF 2025 |
| [pwnfield](2025/N0PSctf/README.md) | pwn | 2025 | N0PSctf |
| [Sweet Game](2024/Affrica%20BattleCTF2024/README.md) | pwn | 2024 | Affrica BattleCTF2024 |
| [filtered](2024/No%20Hack%20No%20CTF%202024/README.md) | pwn | 2024 | No Hack No CTF 2024 |
| [Orange](2024/UrmiaCTF%202024/README.md) | pwn | 2024 | UrmiaCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-socket"></a>
### `socket` (2)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Dupocalypse](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |
| [Tictocket](2024/USCCTF%202024/README.md) | web | 2024 | USCCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-sop"></a>
### `sop` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [double nested](2025/TJCTF%202025/README.md) | web | 2025 | TJCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-srand"></a>
### `srand` (3)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Gamble](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [Mr Unlucky](2025/Nullcon%20Goa%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Goa HackIM 2025 CTF |
| [Sweet Game](2024/Affrica%20BattleCTF2024/README.md) | pwn | 2024 | Affrica BattleCTF2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-srop"></a>
### `srop` (6)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Laconic](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [into the void](2025/K17%20CTF/README.md) | pwn | 2025 | K17 CTF |
| [Size Doesn't Matter](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |
| [notez](2025/QnQSec%20CTF%202025/README.md) | pwn | 2025 | QnQSec CTF 2025 |
| [Giggity Ropity Goo](2025/World%20Wide%20CTF%202025/README.md) | pwn | 2025 | World Wide CTF 2025 |
| [Mixed Signals](2024/niteCTF%202024/README.md) | pwn | 2024 | niteCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-stack"></a>
### `stack` (95)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [adventure](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |
| [guessguesswhosstack](2025/b01lers%20CTF%202025/README.md) | pwn | 2025 | b01lers CTF 2025 |
| [scanner](2025/b01lers%20CTF%202025/README.md) | pwn | 2025 | b01lers CTF 2025 |
| [Gamble](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [Lolimancer](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [BabyPWN](2025/BITSCTF%202025/README.md) | pwn | 2025 | BITSCTF 2025 |
| [File101](2025/BlackHat%20MEA%20CTF%20Qualification%202025/README.md) | pwn | 2025 | BlackHat MEA CTF Qualification 2025 |
| [Safe Note](2025/BlitzCTF/README.md) | pwn | 2025 | BlitzCTF |
| [Obligatory Heap](2025/BrunnerCTF%202025/README.md) | pwn | 2025 | BrunnerCTF 2025 |
| [Guessing Game](2025/BuckeyeCTF%202025/README.md) | pwn | 2025 | BuckeyeCTF 2025 |
| [Game of Yap](2025/BYUCTF%202025/README.md) | pwn | 2025 | BYUCTF 2025 |
| [Goat](2025/BYUCTF%202025/README.md) | pwn | 2025 | BYUCTF 2025 |
| [poisoned bank](2025/cornCTF%202025/README.md) | pwn | 2025 | cornCTF 2025 |
| [tasks](2025/CPCTF%202025/README.md) | pwn | 2025 | CPCTF 2025 |
| [Blessing](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [Contractor](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [Crossbow](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [Laconic](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [Quack quack](2025/Cyber%20Apocalypse%20CTF%202025%20Tales%20from%20Eldoria/README.md) | pwn | 2025 | Cyber Apocalypse CTF 2025 Tales from Eldoria |
| [Clobber](2025/DawgCTF%202025/README.md) | pwn | 2025 | DawgCTF 2025 |
| [xrop](2025/Dreamhack%20CTF%20Season%207%20Round%20%232%20%28Div.%202%29/README.md) | pwn | 2025 | Dreamhack CTF Season 7 Round #2 (Div. 2) |
| [Cash Memo](2025/EHAX%20CTF%202025/README.md) | pwn | 2025 | EHAX CTF 2025 |
| [pearls](2025/Iran%20Tech%20Olympics%20CTF%202025/README.md) | pwn | 2025 | Iran Tech Olympics CTF 2025 |
| [En(d)less behaviour](2025/K%21nd4SUS%20CTF%202025/README.md) | pwn | 2025 | K!nd4SUS CTF 2025 |
| [Vector Madness](2025/K%21nd4SUS%20CTF%202025/README.md) | pwn | 2025 | K!nd4SUS CTF 2025 |
| [holes](2025/K17%20CTF/README.md) | pwn | 2025 | K17 CTF |
| [into the void](2025/K17%20CTF/README.md) | pwn | 2025 | K17 CTF |
| [minecraft](2025/LA%20CTF%202025/README.md) | pwn | 2025 | LA CTF 2025 |
| [Broken](2025/LINE%20CTF%202025/README.md) | pwn | 2025 | LINE CTF 2025 |
| [no nonsesnse](2025/LIT%20CTF%202025/README.md) | pwn | 2025 | LIT CTF 2025 |
| [stillestprintf](2025/LIT%20CTF%202025/README.md) | pwn | 2025 | LIT CTF 2025 |
| [the mound](2025/LIT%20CTF%202025/README.md) | pwn | 2025 | LIT CTF 2025 |
| [pwnfield](2025/N0PSctf/README.md) | pwn | 2025 | N0PSctf |
| [Under Attack](2025/N0PSctf/README.md) | pwn | 2025 | N0PSctf |
| [The Jumps](2025/NahamCon%20CTF%202025/README.md) | pwn | 2025 | NahamCon CTF 2025 |
| [hateful](2025/Nullcon%20Goa%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Goa HackIM 2025 CTF |
| [Mr Unlucky](2025/Nullcon%20Goa%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Goa HackIM 2025 CTF |
| [Mr. %ROPOT%](2025/Pearl%20CTF/README.md) | pwn | 2025 | Pearl CTF |
| [Dupocalypse](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |
| [Intresting](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |
| [Size Doesn't Matter](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |
| [Eistein](2025/PwnMe%20CTF%20Quals%202025/README.md) | pwn | 2025 | PwnMe CTF Quals 2025 |
| [NoPrint](2025/PwnMe%20CTF%20Quals%202025/README.md) | pwn | 2025 | PwnMe CTF Quals 2025 |
| [malloc wrapper part 1](2025/QnQSec%20CTF%202025/README.md) | pwn | 2025 | QnQSec CTF 2025 |
| [notez](2025/QnQSec%20CTF%202025/README.md) | pwn | 2025 | QnQSec CTF 2025 |
| [Bit Burger](2025/RITSEC%20CTF%202025/README.md) | pwn | 2025 | RITSEC CTF 2025 |
| [Hashmatch](2025/RITSEC%20CTF%202025/README.md) | pwn | 2025 | RITSEC CTF 2025 |
| [StarShip Registration](2025/RITSEC%20CTF%202025/README.md) | pwn | 2025 | RITSEC CTF 2025 |
| [Gachiarray](2025/SECCON%20CTF%2014%20Quals/README.md) | pwn | 2025 | SECCON CTF 14 Quals |
| [V-tables](2025/Securinets%20CTF%20Quals%202025/README.md) | pwn | 2025 | Securinets CTF Quals 2025 |
| [blargh](2025/smileyCTF%202025/README.md) | pwn | 2025 | smileyCTF 2025 |
| [Its A Me Jumpio](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |
| [Super Jumpio Kart](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |
| [mucusky](2025/TFC%20CTF%202025/README.md) | pwn | 2025 | TFC CTF 2025 |
| [buggy](2025/TJCTF%202025/README.md) | pwn | 2025 | TJCTF 2025 |
| [linked](2025/TJCTF%202025/README.md) | pwn | 2025 | TJCTF 2025 |
| [Canon Event](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |
| [Free The Monster](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |
| [Virtual Insanity](2025/TRX%20CTF%202025/README.md) | pwn | 2025 | TRX CTF 2025 |
| [one write](2025/UMDCTF%202025/README.md) | pwn | 2025 | UMDCTF 2025 |
| [Kiwiphone](2025/VuwCTF%202025/README.md) | pwn | 2025 | VuwCTF 2025 |
| [Simple AI Bot](2025/WHY2025%20CTF/README.md) | pwn | 2025 | WHY2025 CTF |
| [DryWall](2025/WolvCTF%202025/README.md) | pwn | 2025 | WolvCTF 2025 |
| [Giggity Ropity Goo](2025/World%20Wide%20CTF%202025/README.md) | pwn | 2025 | World Wide CTF 2025 |
| [Baby Kernel](2024/1337UpCTF/README.md) | pwn | 2024 | 1337UpCTF |
| [Floormat Mega Sale](2024/1337UpCTF/README.md) | pwn | 2024 | 1337UpCTF |
| [Retro2Win](2024/1337UpCTF/README.md) | pwn | 2024 | 1337UpCTF |
| [Rigged Slot Machine 2](2024/1337UpCTF/README.md) | pwn | 2024 | 1337UpCTF |
| [NTcrack](2024/Affrica%20BattleCTF2024/README.md) | pwn | 2024 | Affrica BattleCTF2024 |
| [Sweet Game](2024/Affrica%20BattleCTF2024/README.md) | pwn | 2024 | Affrica BattleCTF2024 |
| [calc](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [color](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [runaway0](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [runaway1](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [runaway2](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [runaway3](2024/BuckeyeCTF%202024/pwn/README.md) | pwn | 2024 | BuckeyeCTF 2024 |
| [Crack](2024/H7CTF%202024/README.md) | pwn | 2024 | H7CTF 2024 |
| [Questionaire](2024/H7CTF%202024/README.md) | pwn | 2024 | H7CTF 2024 |
| [Bankrupt](2024/HeroCTFv6/README.md) | pwn | 2024 | HeroCTFv6 |
| [Copy & Waste](2024/IERAE-CTF%202024/README.md) | pwn | 2024 | IERAE-CTF 2024 |
| [This is a warmup](2024/IERAE-CTF%202024/README.md) | pwn | 2024 | IERAE-CTF 2024 |
| [Mixed Signals](2024/niteCTF%202024/README.md) | pwn | 2024 | niteCTF 2024 |
| [Print The Gifts](2024/niteCTF%202024/README.md) | pwn | 2024 | niteCTF 2024 |
| [dof](2024/No%20Hack%20No%20CTF%202024/README.md) | pwn | 2024 | No Hack No CTF 2024 |
| [filtered](2024/No%20Hack%20No%20CTF%202024/README.md) | pwn | 2024 | No Hack No CTF 2024 |
| [fishbabys library](2024/No%20Hack%20No%20CTF%202024/README.md) | pwn | 2024 | No Hack No CTF 2024 |
| [grading system](2024/No%20Hack%20No%20CTF%202024/README.md) | pwn | 2024 | No Hack No CTF 2024 |
| [Slime Machine Challenge](2024/No%20Hack%20No%20CTF%202024/README.md) | pwn | 2024 | No Hack No CTF 2024 |
| [Not So Shrimple Is It](2024/PatriotCTF%202024/README.md) | pwn | 2024 | PatriotCTF 2024 |
| [Infinite Recursion](2024/THJCC%20CTF%202024%20winter/README.md) | pwn | 2024 | THJCC CTF 2024 winter |
| [The Best Anime](2024/THJCC%20CTF%202024%20winter/README.md) | pwn | 2024 | THJCC CTF 2024 winter |
| [Look Up](2024/UrmiaCTF%202024/README.md) | pwn | 2024 | UrmiaCTF 2024 |
| [Orange](2024/UrmiaCTF%202024/README.md) | pwn | 2024 | UrmiaCTF 2024 |
| [Portal](2024/USCCTF%202024/README.md) | pwn | 2024 | USCCTF 2024 |
| [Readers](2024/USCCTF%202024/README.md) | pwn | 2024 | USCCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-stack-pivot"></a>
### `stack pivot` (5)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Obligatory Heap](2025/BrunnerCTF%202025/README.md) | pwn | 2025 | BrunnerCTF 2025 |
| [minecraft](2025/LA%20CTF%202025/README.md) | pwn | 2025 | LA CTF 2025 |
| [Dupocalypse](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |
| [Baby Kernel](2025/UIUCTF%202025/README.md) | pwn | 2025 | UIUCTF 2025 |
| [Giggity Ropity Goo](2025/World%20Wide%20CTF%202025/README.md) | pwn | 2025 | World Wide CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-stderr"></a>
### `stderr` (7)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [ourukla](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |
| [The Last Duel](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [File101](2025/BlackHat%20MEA%20CTF%20Qualification%202025/README.md) | pwn | 2025 | BlackHat MEA CTF Qualification 2025 |
| [beating yellow king with musl in ng+](2025/niteCTF%202025/README.md) | pwn | 2025 | niteCTF 2025 |
| [Fotispy 7](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |
| [Gachiarray](2025/SECCON%20CTF%2014%20Quals/README.md) | pwn | 2025 | SECCON CTF 14 Quals |
| [EzDB](2025/TPCTF%202025/README.md) | pwn | 2025 | TPCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-stdout"></a>
### `stdout` (10)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [tcademy](2026/LA%20CTF%202026/README.md) | pwn | 2026 | LA CTF 2026 |
| [scanner](2025/b01lers%20CTF%202025/README.md) | pwn | 2025 | b01lers CTF 2025 |
| [File101](2025/BlackHat%20MEA%20CTF%20Qualification%202025/README.md) | pwn | 2025 | BlackHat MEA CTF Qualification 2025 |
| [Merger](2025/KalmarCTF%202025/README.md) | pwn | 2025 | KalmarCTF 2025 |
| [minecraft](2025/LA%20CTF%202025/README.md) | pwn | 2025 | LA CTF 2025 |
| [hateful2](2025/Nullcon%20Goa%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Goa HackIM 2025 CTF |
| [Eistein](2025/PwnMe%20CTF%20Quals%202025/README.md) | pwn | 2025 | PwnMe CTF Quals 2025 |
| [limit](2025/smileyCTF%202025/README.md) | pwn | 2025 | smileyCTF 2025 |
| [no view](2025/TSCCTF%202025/noview%20%28Up%20Solved%29/README.md) | pwn | 2025 | TSCCTF 2025 |
| [screenwriter](2024/Wargames.MY%20CTF%202024/README.md) | pwn | 2024 | Wargames.MY CTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-syscall"></a>
### `syscall` (3)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [NiteBus](2025/niteCTF%202025/README.md) | pwn | 2025 | niteCTF 2025 |
| [Size Doesn't Matter](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |
| [Mixed Signals](2024/niteCTF%202024/README.md) | pwn | 2024 | niteCTF 2024 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-tcache-poison"></a>
### `tcache poison` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [poisoned bank](2025/cornCTF%202025/README.md) | pwn | 2025 | cornCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-toctou"></a>
### `toctou` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [reloc8](2025/Null%20CTF%202025/README.md) | pwn | 2025 | Null CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-type-confusion"></a>
### `type confusion` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [VowBreaker](2025/NexHunt%20CTF/README.md) | pwn | 2025 | NexHunt CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-uaf"></a>
### `uaf` (4)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [phantom](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |
| [poisoned bank](2025/cornCTF%202025/README.md) | pwn | 2025 | cornCTF 2025 |
| [account management](2025/Iran%20Tech%20Olympics%20CTF%202025/README.md) | pwn | 2025 | Iran Tech Olympics CTF 2025 |
| [Baby Kernel](2025/UIUCTF%202025/README.md) | pwn | 2025 | UIUCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-unsafe-unlink"></a>
### `unsafe unlink` (7)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [67 revenge](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |
| [Santa's Workshop](2025/BackdoorCTF%202025/README.md) | pwn | 2025 | BackdoorCTF 2025 |
| [Safe Note](2025/BlitzCTF/README.md) | pwn | 2025 | BlitzCTF |
| [Fotispy 4](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |
| [Fotispy 7](2025/Nullcon%20Berlin%20HackIM%202025%20CTF/README.md) | pwn | 2025 | Nullcon Berlin HackIM 2025 CTF |
| [limit](2025/smileyCTF%202025/README.md) | pwn | 2025 | smileyCTF 2025 |
| [one write](2025/UMDCTF%202025/README.md) | pwn | 2025 | UMDCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-unsorted-bins-attack"></a>
### `unsorted bins attack` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Refreshments](2025/StackSmash%20CTF/README.md) | pwn | 2025 | StackSmash CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-upx"></a>
### `upx` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Intresting](2025/Pragyan%20CTF%202025/README.md) | pwn | 2025 | Pragyan CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-v8"></a>
### `v8` (4)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [The Butterfly Effect](2025/Infobahn%20CTF%202025/README.md) | pwn | 2025 | Infobahn CTF 2025 |
| [VowBreaker](2025/NexHunt%20CTF/README.md) | pwn | 2025 | NexHunt CTF |
| [reloc8](2025/Null%20CTF%202025/README.md) | pwn | 2025 | Null CTF 2025 |
| [optimization](2025/RSTCON%202025%20CTF/README.md) | pwn | 2025 | RSTCON 2025 CTF |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-vm"></a>
### `vm` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [chaos](2026/0xFUN%20CTF%202026/README.md) | pwn | 2026 | 0xFUN CTF 2026 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-www"></a>
### `www` (6)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [pwn a brainrot](2025/Infobahn%20CTF%202025/README.md) | pwn | 2025 | Infobahn CTF 2025 |
| [no nonsesnse](2025/LIT%20CTF%202025/README.md) | pwn | 2025 | LIT CTF 2025 |
| [Cursed ST](2025/SECCON%20CTF%2014%20Quals/README.md) | pwn | 2025 | SECCON CTF 14 Quals |
| [Gachiarray](2025/SECCON%20CTF%2014%20Quals/README.md) | pwn | 2025 | SECCON CTF 14 Quals |
| [Kiwiphone](2025/VuwCTF%202025/README.md) | pwn | 2025 | VuwCTF 2025 |
| [Take Note](2025/WolvCTF%202025/README.md) | pwn | 2025 | WolvCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-www2"></a>
### `www2` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [guessguesswhosstack](2025/b01lers%20CTF%202025/README.md) | pwn | 2025 | b01lers CTF 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-www2exec"></a>
### `www2exec` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [Eistein](2025/PwnMe%20CTF%20Quals%202025/README.md) | pwn | 2025 | PwnMe CTF Quals 2025 |

[Back to tag navigation](#technique-tag-navigation)

<a id="tag-xss"></a>
### `xss` (1)

| Challenge | Category | Year | CTF |
| --- | :---: | :---: | --- |
| [double nested](2025/TJCTF%202025/README.md) | web | 2025 | TJCTF 2025 |

[Back to tag navigation](#technique-tag-navigation)
