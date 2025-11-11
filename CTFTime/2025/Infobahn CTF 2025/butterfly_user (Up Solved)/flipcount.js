// Base tagged pointer
const base = 0x000007bd0080b4f1n;

for (let k = 0n; k <= 63n; k++) {
  const mask = 1n << k;
  const flipped = base ^ mask;

  console.log(
    "bit", k.toString().padStart(2, " "),
    "-> 0x" + flipped.toString(16)
  );
}
