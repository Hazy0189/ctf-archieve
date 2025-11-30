#!/usr/bin/env python3
from os import path, remove
import sys
from argparse import ArgumentParser
from subprocess import Popen, PIPE, TimeoutExpired
import threading
from concurrent.futures import ThreadPoolExecutor, as_completed
from re import search
import requests

# ---- tiny color helpers (simple, no deps) ----
USE_COLOR = sys.stdout.isatty()
def _c(s, code): return f"\x1b[{code}m{s}\x1b[0m" if USE_COLOR else s
BOLD = lambda s: _c(s, "1")
CYAN = lambda s: _c(s, "36")
YELL = lambda s: _c(s, "33")
RED  = lambda s: _c(s, "31")
CLR_EOL = "\x1b[0K" if USE_COLOR else ""

FLAG_LOCK = threading.Lock()
sess = requests.Session()
TIMEOUT = 5

is_ipv4 = lambda s: len(s.split('.')) == 4 and all(p.isdigit() and 0 <= int(p) <= 255 for p in s.split('.'))
is_domain = lambda s: all(part.isalnum() or part == '-' for part in s.split('.'))
is_port = lambda s: s.isdigit() and 0 <= int(s) <= 65535

# ---- Argument parser ----
def parse_args():
    p = ArgumentParser(description="Target runner")
    p.add_argument("-v", "--verbose", action="store_true", default=False,
                   help="Show exploit.py output (streamed).")
    p.add_argument("-t", "--threads", type=int, default=4,
                   help="Number of parallel threads (default=4).")
    p.add_argument("--timeout", type=int, default=10,
                   help="Timeout in seconds for each exploit (default=10).")
    return p.parse_args()

# ---- Helper functions ----
def fix_path(p):
    p = p.strip()
    if not p:
        return p
    if path.isabs(p):
        return path.abspath(p)
    base = path.dirname(path.abspath(__file__))
    return path.abspath(path.join(base, p))

def request(method, url, headers=None, json=None, data=None, params=None):
    req = requests.Request(method, url, headers=headers, json=json, data=data, params=params)
    prep = sess.prepare_request(req)
    return sess.send(prep, timeout=TIMEOUT)

def execute(cmds, verbose=False, timeout=None):
    cmds = cmds if isinstance(cmds, list) else cmds.split()
    if verbose:
        sys.stdout.write("\n")
        sys.stdout.flush()
        p = Popen(cmds, stdout=PIPE, stderr=sys.stdout, text=True, bufsize=1)
        buf = []
        try:
            for line in p.stdout:
                sys.stdout.write(line)
                sys.stdout.flush()
                buf.append(line)
            p.wait(timeout=timeout)
        except TimeoutExpired:
            p.kill()
            sys.stdout.write(RED(f"[!] Command timed out after {timeout}s:\n  {' '.join(cmds)}") + "\n")
            sys.stdout.flush()
        return "".join(buf)
    else:
        p = Popen(cmds, stdout=PIPE, stderr=sys.stdout, text=True)
        try:
            out, err = p.communicate(timeout=timeout)
        except TimeoutExpired:
            p.kill()
            sys.stdout.write(RED(f"[!] Command timed out after {timeout}s:\n  {' '.join(cmds)}") + "\n")
            sys.stdout.flush()
            return None
        return out if out else err

def status_update(target_str, attempt, idx, total, flag=None):
    cur = idx + 1
    remaining = total - cur
    pct = int((cur / total) * 100) if total > 0 else 100
    line = f"{BOLD('[!]')} Target {CYAN(target_str)} {BOLD('|')} Attempt: {YELL(attempt)}"
    line += f" {BOLD('|')} {cur}/{total} ({pct}%)"
    if remaining > 0:
        line += f" {BOLD('|')} left: {YELL(remaining)}"
    if flag:
        line += f" {BOLD('|')} Found flag -> {YELL(flag)}"
    sys.stdout.write("\r" + line + CLR_EOL)
    sys.stdout.flush()

# ---- Target reader and runner ----
def read_targets(file_path, default_ip='127.0.0.1', default_port='31337'):
    targets = []
    try:
        with open(fix_path(file_path), encoding='utf-8') as f:
            for ln in f:
                s = ln.strip()
                if not s or s.startswith('#'):
                    continue
                parts = s.split()
                if len(parts) > 1:
                    ip, port = parts[0], parts[1]
                elif ':' in parts[0]:
                    ip, port = parts[0].split(':', 1)
                else:
                    ip = None if is_port(parts[0]) else parts[0]
                    port = parts[0] if is_port(parts[0]) else None
                ip = ip if ip and (is_ipv4(ip) or is_domain(ip)) else default_ip
                port = port if port and is_port(port) else default_port
                targets.append((ip, str(port)))
    except FileNotFoundError:
        pass
    return targets

def run_target(ip, port, idx, total, exploit_path, flag_regex, verbose=False, timeout=10):
    target_str = f"{ip}:{port}" if port else ip
    try:
        status_update(target_str, 1, idx, total)
        exploit_abspath = fix_path(exploit_path) if not path.isabs(exploit_path) else exploit_path
        if not path.exists(exploit_abspath):
            sys.stdout.write("\n" + RED(f"[!] exploit not found: {exploit_abspath}") + "\n")
            sys.stdout.flush()
            return None
        out = execute([sys.executable, exploit_abspath, ip, port], verbose=verbose, timeout=timeout)
        match = search(flag_regex, out) if out else None
        flag = match.group(1) if match else None
        status_update(target_str, 1, idx, total, flag=flag)
        sys.stdout.write("\n")
        sys.stdout.flush()
        if flag:
            with FLAG_LOCK:
                with open("flag.txt", "ab") as f:
                    f.write(flag.encode() + b"\n")
        return flag
    except KeyboardInterrupt:
        sys.stdout.write("\n" + RED(f"[!] Stopped {target_str}") + "\n")
        sys.stdout.flush()
        return None

# ---- IP/Port updater and flag submitter ----
def update_ip_ports(base_url, token, filename='ip_port.txt'):
    try:
        resp = request("GET", f"{base_url}/api/user", headers={"Authorization": f"Bearer {token}"})
        data = resp.json() if isinstance(resp.json(), list) else [resp.json()]
        entries = [f"{d.get('ip') or d.get('host')} {d.get('port')}" if d.get('port') 
                   else d.get('ip') or d.get('host') for d in data if isinstance(d, dict) and (d.get('ip') or d.get('host'))]
        if entries:
            open(filename, 'w').write('\n'.join(entries))
            print(f"[i] Updated {filename} with {len(entries)} entry(s)")
    except Exception as e:
        print(f"[!] Error: {e}")

def submit_flags(base_url, token, flag_file='flag.txt'):
    try:
        with open(flag_file, 'r', encoding='utf-8') as f:
            flags = [line.strip() for line in f if line.strip() and not line.startswith('#')]
        if not flags:
            return
        url = f"{base_url}/api/flag"
        headers = {"Authorization": f"Bearer {token}", "Content-Type": "application/json"}
        for flag in flags:
            try:
                resp = request("POST", url, headers=headers, json={"flag": flag})
                msg = resp.json().get('message', resp.text[:100]) if resp.ok else resp.text[:100]
                print(f"[*] {flag}: {resp.status_code} -> {msg}")
            except Exception as e:
                print(f"[!] {flag}: Error -> {e}")
        remove(flag_file)
    except FileNotFoundError:
        pass

# ---- Main execution ----
def main():
    args = parse_args()
    flag_regex = r'GEMASTIK18\{([^}]+)\}'
    base_url = 'https://gemastik-api.siberlab.id'
    token = 'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJmcmVzaCI6ZmFsc2UsImlhdCI6MTc2MTYzNTgzNSwianRpIjoiNjkwOTkzNzctZmI2MC00YWRlLWE0ZWItMTRkMThmNTU1ZjdiIiwidHlwZSI6ImFjY2VzcyIsInN1YiI6IkNZSCIsIm5iZiI6MTc2MTYzNTgzNSwiY3NyZiI6ImYyMGJjZTE4LWViMjgtNDg0ZS04MWE3LTlmYWE2OWMyYjk1ZiIsImV4cCI6MTc2MTcyMjIzNX0.D0RN5TxN86Fr4Ny2E0LyafXyolHrUjnOPgbHGTHwVwM'
    update_ip_ports(base_url=base_url, token=token)
    all_tasks = [
        (read_targets('ip_port.txt', default_port='11000'), 'challenges/carbeat/exploit.py')
        # (read_targets('ip_port.txt', default_port='11001'), 'challenges/carbeat1/exploit.py'),
        # (read_targets('ip_port.txt', default_port='11002'), 'challenges/carbeat2/exploit.py'),
    ]
    with ThreadPoolExecutor(max_workers=args.threads) as executor:
        futures = [executor.submit(run_target, ip, port, i, len(tgts), exp, flag_regex, args.verbose, args.timeout)
                   for tgts, exp in all_tasks for i, (ip, port) in enumerate(tgts)]
        try:
            for f in as_completed(futures):
                f.result()
        except KeyboardInterrupt:
            print(RED("\n[!] Interrupted"))
            executor.shutdown(wait=False)
            return 1
    submit_flags(base_url=base_url, token=token)
    return 0

if __name__ == '__main__':
    sys.exit(main())
