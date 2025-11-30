import sys
import re
from pathlib import Path

PATTERN = re.compile(r"GEMASTIK18\{(.*?)\}", re.DOTALL)  # non-greedy, spans newlines

def main():
    in_path = Path(sys.argv[1]) if len(sys.argv) >= 2 else Path("unclean_flag.txt")
    out_path = Path(sys.argv[2]) if len(sys.argv) >= 3 else Path("flag.txt")
    try:
        text = in_path.read_text(encoding="utf-8", errors="replace")
    except FileNotFoundError:
        print(f"[!] Input file not found: {in_path}")
        raise SystemExit(1)
    inner_chunks = PATTERN.findall(text)
    if not inner_chunks:
        print("[i] No matches found with pattern GEMASTIK18{.*}")
        return
    with out_path.open("a", encoding="utf-8") as f:
        for chunk in inner_chunks:
            f.write(chunk.strip() + "\n")

    print(f"[✓] Appended {len(inner_chunks)} extracted value(s) to {out_path}")

if __name__ == "__main__":
    main()
