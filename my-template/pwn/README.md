# 🧠 Heap Exploitation Cheatsheet

This is my litetle cheatsheet to remind technique exist in heap

## 🔍 Heap Leak Techniques

### 📌 Tcache Leak (Chunks < 0x420)
- Allocate a small chunk (`size < 0x420`) then free it to move it into the **tcache bin**. Leak its pointer via **Use-After-Free** or **unsanitized read**.

### 📌 Fastbin Leak (`size <= global_max_fast`)
- Fill the **tcache bin** for a size class (up to 7 chunks). Free another chunk of the same size — it will now go to the **fastbin**. Leak the **fastbin** pointer.
Note: **fastbin** allocation based on the global_max_fast value (default 0x80)

### 📌 Largebin Leak
- Free a large chunk (`size > 0x420`) to the **unsorted bin** then allocate a larger chunk to trigger **consolidation into largebin**.

---

## 📥 Libc Leak via Heap

### 📌 Unsorted Bin
- Free a large chunk (`size > 0x420`) and add guard chunk after it to get the **unsorted bin**.
- Fill the **tcache bin** for a size  (`size > global_max_fast`) class (up to 7 chunks). Free another chunk of the same size — it will now go to the **unsorted bins**. Leak the **fastbin** pointer.
Note: **unsortedbins** allocation in the **fastbin** based on the global_max_fast value (default 0x80)

### 📌 Smallbin Leak
- If scanf exist, fill tcache for a small size chunk. Additional freed chunks go into the **fastbin**. After that just send 1024 bytes at scanf.

### 📌 Largebin
- Same method as above. Free large chunk to **unsorted bin**. Allocate a larger chunk then **unsorted bin** to trigger **move to largebin**.

---

## 🧪 Heap Manipulation Techniques

- **Overlapping Chunks** – Forge chunk sizes to overlap adjacent ones.
- **Misaligned Chunks** – Corrupt header to cause size misalignment.
- **Header Corruption** – Modify `size`, `prev_size` fields.
- **Double Free**:
  - Null tcache `key` (`chunk[1] = 0`) to allow reuse.
  - Use it for **tcache poisoning**.
  - `House of Botcake`
- **Tcache Poisoning** – Overwrite freelist pointer (`fd`) to get arbitrary `malloc`.
- **Unsafe Unlink Attack**:
  - Requires null-byte overwrite.
  - Fake `fd` / `bk` pointers in large/small bins.

---

## 🚩 Exploitation Techniques

### 🔧 Libc < 2.34 (Hook Overwrite)
- Overwrite `__free_hook` with:
  - one_gadget
  - `system`

### 📦 Leak Stack via `environ`
- Leak `__environ` → get **stack address**.
- Use:
  - `leave; ret` to pivot to fake stack
  - Overwrite return address

### 💣 FSOP (File Stream Oriented Programming)
- Overwrite `_IO_FILE` structures:
  - Common target: `_IO_2_1_stderr_`
- Trigger `vtable` call using `exit()`.

### 🧰 Return Address Hijack
- Overwrite `ret` with gadget (e.g., `one_gadget`, ROP chain).
- Or target `ret - 8` with `rbp` to use `leave; ret`.
- Overwrite `ret` with exit and continue with fsop or hijack tls exit.
- Overwrite `ret` with `read [rbp - 0x20]` gadget.
- Overwrite `ret` with `add rsp, ??` gadget.

### ⚙️ GOT Overwrite
- Overwrite entries like `puts@GOT`, `exit@GOT` or even libc got.
- Redirect to:
  - `system`
  - one_gadget

### 🎯 Heap Pointer Overwrite
- Overwrite function pointers or vtables stored in heap.
- Hijack control flow or data structure access.

---