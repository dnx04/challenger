from math import isqrt

import numpy as np

MOD = 1234567891
ORD = MOD - 1
N = 10 ** 14
B = 1 << 16
CHUNK = 1 << 21


def tables():
    small = np.empty(B, dtype=np.int64)
    x = 1
    for i in range(B):
        small[i] = x
        x = x * 2 % MOD
    big = np.empty(ORD // B + 2, dtype=np.int64)
    g = pow(2, B, MOD)
    y = 1
    for i in range(big.size):
        big[i] = y
        y = y * g % MOD
    return small, big


def pow2(e, small, big):
    e = e % ORD
    return big[e // B] * small[e % B] % MOD


def solve(n=N):
    small, big = tables()
    k = isqrt(n)
    total = (n * (n + 1) // 2) % MOD * pow(2, (n - 1) % ORD, MOD) % MOD

    s = 0
    for start in range(1, k + 1, CHUNK):
        ks = np.arange(start, min(start + CHUNK, k + 1), dtype=np.int64)
        p2 = pow2(n - n // ks, small, big)
        s = (s + int(((ks % MOD) * p2 % MOD).sum())) % MOD

    top = n // (k + 1)
    for start in range(1, top + 1, CHUNK):
        vs = np.arange(start, min(start + CHUNK, top + 1), dtype=np.int64)
        hi = n // vs
        lo = np.maximum(n // (vs + 1) + 1, k + 1)
        m = lo <= hi
        vs, hi, lo = vs[m], hi[m], lo[m]
        a, b = lo + hi, hi - lo + 1
        even = a % 2 == 0
        cnt = np.where(even, a // 2, a) % MOD * (np.where(even, b, b // 2) % MOD) % MOD
        p2 = pow2(n - vs, small, big)
        s = (s + int((cnt * p2 % MOD).sum())) % MOD

    return (total - s) % MOD


if __name__ == "__main__":
    print(solve(10))
    print(solve())
