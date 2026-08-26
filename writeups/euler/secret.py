import sys
from collections import Counter

import numpy as np
from PIL import Image

MOD = 7
STEPS = 10 ** 12


def load(path):
    img = Image.open(path)
    if img.mode in ("L", "P"):
        return np.array(img, dtype=np.int64)
    return np.array(img.convert("L"), dtype=np.int64)


def digits(n, base):
    out = []
    while n:
        out.append(n % base)
        n //= base
    return out


def step(a, shift):
    h, w = a.shape
    dy, dx = shift % h, shift % w
    r = np.roll(a, dy, axis=0) + np.roll(a, -dy, axis=0)
    r += np.roll(a, dx, axis=1) + np.roll(a, -dx, axis=1)
    return r % MOD


def evolve(a, steps=STEPS):
    a = a % MOD
    for k, d in enumerate(digits(steps, MOD)):
        shift = MOD ** k
        for _ in range(d):
            a = step(a, shift)
    return a


def main():
    src = sys.argv[1] if len(sys.argv) > 1 else "secret.png"
    a = load(src)
    print(a.shape, sorted(Counter(a.ravel() % MOD).items()))
    res = evolve(a)
    counts = Counter(res.ravel().tolist())
    print(sorted(counts.items()))
    Image.fromarray((res * 36).astype(np.uint8)).save("secret_mod7.png")
    bg = counts.most_common(1)[0][0]
    Image.fromarray(np.where(res == bg, 255, 0).astype(np.uint8)).save("secret_word.png")
    for v in range(MOD):
        Image.fromarray(np.where(res == v, 0, 255).astype(np.uint8)).save(f"secret_r{v}.png")


if __name__ == "__main__":
    main()
