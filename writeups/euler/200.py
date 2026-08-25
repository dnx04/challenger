# use sagemath

from itertools import islice

L = 10^12

def proof(n):
    s = str(n)
    return not any(is_prime(ZZ(s[:i] + d + s[i+1:]))
                   for i, c in enumerate(s) for d in '0123456789'
                   if d != c and (i or d != '0'))

squbes = sorted(p^2 * q^3 for q in prime_range(L.nth_root(3, truncate_mode=1)[0] + 1)
                          for p in prime_range(isqrt(L // q^3) + 1) if p != q)

print(next(islice((n for n in squbes if '200' in str(n) and proof(n)), 199, None)))
