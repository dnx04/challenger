"""Tong G(n^3) voi 1 <= n < 10^6, G = day Golomb (A001462).

Y tuong: G tu mo ta -> gia tri k chiem dung G(k) vi tri lien tiep.
  cum[k] = G(1)+...+G(k)  = vi tri cuoi cung mang gia tri k
  => G(m) = k nho nhat sao cho cum[k] >= m.
Can k toi ~1.6e11 nen khong dung mang truc tiep duoc, nhung cum(p) voi p lon
tinh duoc tu bang nho: voi r = G(p),  cum(p) = T[r-1] + r*(p - cum[r-1]),
trong do T[q] = sum_{i<=q} i*G(i).  Bang chi can dai ~ (1e18)^0.382 ~ 1.2e7.
"""
from array import array
from bisect import bisect_left
import time

M = 12_000_000
t0 = time.time()

g = array('q', [0, 1])
cum = array('q', [0, 1])
T = array('q', [0, 1])
ga, ca, Ta = g.append, cum.append, T.append
for k in range(1, M):
    v = 1 + g[k + 1 - g[g[k]]]
    ga(v)
    ca(cum[k] + v)
    Ta(T[k] + (k + 1) * v)
print(f"bang xong: M={M}, cum[M]={cum[M]:.3e}, {time.time()-t0:.1f}s", flush=True)

LIMIT = cum[M]

def cumG(p):
    r = bisect_left(cum, p)
    return T[r - 1] + r * (p - cum[r - 1])

def G(m):
    lo, hi = 1, LIMIT
    while lo < hi:
        mid = (lo + hi) >> 1
        if cumG(mid) < m:
            lo = mid + 1
        else:
            hi = mid
    return lo

# kiem tra lai voi bang truc tiep
assert all(G(m) == g[m] for m in range(1, 200))
assert all(G(m) == g[m] for m in range(1, 5_000_000, 7919))
print("G() khop bang truc tiep", flush=True)
print("kiem tra rieng: tong n<170 =", sum(G(n**3) for n in range(1, 170)),
      "| truc tiep:", sum(g[n**3] for n in range(1, 170)), flush=True)

t1 = time.time()
total = 0
for n in range(1, 10**6):
    total += G(n * n * n)
print(f"\nsum G(n^3), 1<=n<10^6 = {total}   ({time.time()-t1:.1f}s)", flush=True)
