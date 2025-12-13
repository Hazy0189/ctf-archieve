#!/usr/bin/env python3
from pwn import *
import sys

def send_poc(file_path, host="ctf.nexus-security.club", port=2761):
    try:
        # Read the PoC JavaScript file
        with open(file_path, "r") as f:
            poc_script = f.read()

        # Connect to the server using pwntools
        log.info(f"Connecting to {host}:{port}...")
        conn = remote(host, port)

        # Send the size of the script first
        script_size = len(poc_script)
        conn.sendline(str(script_size))

        # Send the script content
        conn.send(poc_script)
        log.info("PoC sent. Switching to interactive mode...")

        # Switch to interactive mode
        conn.interactive()

    except FileNotFoundError:
        log.error(f"Error: File '{file_path}' not found.")
    except ConnectionRefusedError:
        log.error(f"Error: Unable to connect to {host}:{port}.")
    except Exception as e:
        log.error(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <path_to_poc.js>")
        sys.exit(1)

    poc_file = sys.argv[1]
    send_poc(poc_file)