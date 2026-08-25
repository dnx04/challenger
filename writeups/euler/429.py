from sage.arith.misc import next_prime
MOD = 10^9 + 9
N = 10^8

# vp(n!)
def legendre(n, p):
    res = 0
    base = 1
    while True:
        base *= p
        if base > n:
            break
        res += n // base
    return res

ans = 1
p = 2
while p <= N:
    ans *= (pow(p, 2 * legendre(N, p), MOD) + 1)
    ans %= MOD
    p = next_prime(p)

print(ans)
