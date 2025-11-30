#!/usr/bin/env python3
import argparse
import re
import sys
import urllib.parse
import requests
from bs4 import BeautifulSoup

# -------------------- Session / Globals --------------------
sess = requests.Session()

def normalize_base_url(u: str) -> str:
    """Ensure scheme present and strip paths. e.g. '102.32.23.21' -> 'http://102.32.23.21'."""
    if not re.match(r'^[a-zA-Z][a-zA-Z0-9+.-]*://', u):
        u = 'http://' + u
    p = urllib.parse.urlsplit(u)
    return f'{p.scheme}://{p.netloc}'.rstrip('/')

# -------------------- Pretty request/response --------------------
def response(resp: requests.Response):
    """Print Burp-style raw request/response + friendly summary."""
    preq = resp.request
    u = urllib.parse.urlsplit(preq.url)
    path = u.path or "/"
    if u.query:
        path += "?" + u.query

    print("### Request (raw)")
    print(f"{preq.method} {path} HTTP/1.1")
    host_in_headers = any(k.lower() == "host" for k in preq.headers)
    if not host_in_headers:
        print(f"Host: {u.netloc}")
    for k, v in preq.headers.items():
        print(f"{k}: {v}")
    print()
    body = preq.body
    if body:
        if isinstance(body, bytes):
            try:
                body = body.decode("utf-8")
            except Exception:
                body = body.decode("latin-1", errors="replace")
        print(body)
    print()

    httpver = {10: "HTTP/1.0", 11: "HTTP/1.1"}.get(getattr(resp.raw, "version", 11), "HTTP/1.1")
    print("### Response (raw)")
    print(f"{httpver} {resp.status_code} {resp.reason}")
    for k, v in resp.headers.items():
        print(f"{k}: {v}")
    print()
    print(resp.text)
    print("\n" + "="*80 + "\n")

    print("### Summary")
    print(f"URL:     {resp.url}")
    print(f"Status:  {resp.status_code} {resp.reason}")
    print("-- Response Headers --")
    for k, v in resp.headers.items():
        print(f"{k}: {v}")
    print("-- Body --")
    print(resp.text)
    print("\n" + "="*80 + "\n")

# -------------------- Thin wrapper --------------------
def request(method, url, headers=None, json=None, data=None, params=None, files=None, show=False):
    req = requests.Request(method, url, headers=headers, json=json, data=data, params=params, files=files)
    prep = sess.prepare_request(req)
    resp = sess.send(prep, timeout=TIMEOUT)
    if show:
        response(resp)
    return resp

# -------------------- Helpers --------------------
def get_csrf_from_html(html: str):
    soup = BeautifulSoup(html, 'html.parser')
    csrf_input = soup.find('input', attrs={'name': '_csrf'}) or soup.find('input', attrs={'id': 'csrfToken'})
    return csrf_input.get('value') if csrf_input else None

# def register(base_url, username, password, show=False):
#     resp = request("GET", f"{base_url}/register", show=show)
#     csrf = get_csrf_from_html(resp.text)
#     payload = {"_csrf": csrf, "username": username, "password": password}
#     headers_post = {"Content-Type": "application/json"}
#     return request("POST", f"{base_url}/auth/register", headers=headers_post, json=payload, show=show)

# def login(base_url, username, password, show=False):
#     resp = request("GET", f"{base_url}/login", show=show)
#     csrf = get_csrf_from_html(resp.text)
#     payload = {"_csrf": csrf, "username": username, "password": password}
#     headers_post = {"Content-Type": "application/json"}
#     return request("POST", f"{base_url}/auth/login", headers=headers_post, json=payload, show=show)

# def upload_file(base_url, file_path, show=False):
#     resp = request("GET", f"{base_url}/upload", show=show)
#     csrf = get_csrf_from_html(resp.text)
#     with open(file_path, 'rb') as f:
#         files = {'file': (file_path, f)}
#         data = {'_csrf': csrf}
#         return request("POST", f"{base_url}/upload", data=data, files=files, show=show)


def parse_args():
    p = argparse.ArgumentParser(description="CTF helper with Burp-style request/response.")
    p.add_argument("ip", help="Target IP address")
    p.add_argument("port", help="Target port")
    p.add_argument("-x", "--proxy", help="HTTP/HTTPS proxy, e.g. http://127.0.0.1:8080")
    p.add_argument("--insecure", action="store_true", help="Disable TLS certificate verification.")
    p.add_argument("--timeout", type=int, default=15, help="Request timeout (seconds).")
    p.add_argument("--show", action="store_true", help="Print raw requests/responses.")
    return p.parse_args()

def main():
    global TIMEOUT
    args = parse_args()
    base_url = normalize_base_url(f"{args.ip}:{args.port}")

    sess.proxies.clear()
    if args.proxy:
        sess.proxies.update({"http": args.proxy, "https": args.proxy})
    sess.verify = not args.insecure
    TIMEOUT = args.timeout
    print(f"[i] Target      : {base_url}")
    print(f"[i] Proxy       : {args.proxy or '-'}")
    print(f"[i] TLS verify  : {sess.verify}")
    print(f"[i] Timeout     : {TIMEOUT}s")


if __name__ == "__main__":
    try:
        main()
    except requests.RequestException as e:
        print(f"[!] HTTP error: {e}")
        sys.exit(2)
    except KeyboardInterrupt:
        print("\n[!] Interrupted.")
        sys.exit(130)
