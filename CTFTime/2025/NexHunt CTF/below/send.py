#!/usr/bin/python3
from pwn import *
import os
os.environ["PWNLIB_NOTERM"] = "1"

def send_file(src, dst):
    data = b64e(read(src))

    p.sendlineafter("$", "stty -echo")
    p.sendlineafter("$", f"base64 -d <<EOF > {dst}")

    size = 1200 # max should be around 1440 (default MTU is 1500)
    nchunks = len(data) // size
    for i in range(nchunks + 1):
        log.info(f"Sending chunk {i}/{nchunks}")
        p.sendline(data[i*size:(i+1)*size]) # TCP will handle any out-of-order possibilities on server side
        sleep(0.01) # probably dont need this, but to prevent the possible random case of out-of-order from client side
    p.sendline("EOF")

    p.sendlineafter("$", f"chmod +x {dst}")
    p.sendlineafter("$", f"{dst}")


if __name__ == "__main__":
    if len(sys.argv) != 5:
        print("usage: ./send.py <IP> <PORT> <FILE TO SEND> <PATH ON REMOTE>")
        exit(-1)

    ip = sys.argv[1]
    port = int(sys.argv[2])

    src_file = sys.argv[3]
    dst_file = sys.argv[4]

    p = remote(ip, port)
    send_file(src_file, dst_file)

    p.interactive()