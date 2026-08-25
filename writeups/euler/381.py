from sage.arith.misc import next_prime
from sage.arith.misc import inverse_mod

ans = 0
p = 5
N = 10^8
while p <= N:
    base = p - 1
    add = 0
    for i in range(1, 6):
        if p == 5 and i == 5:
            add += 1
            continue
        add += base
        base = base * inverse_mod(p - i, p) % p
    ans += add % p
    p = next_prime(p)


print(ans)
