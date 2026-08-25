N, M = 10^6, 1005000
P = {n: euler_phi(n) for n in range(N, M)}
print(sum(crt(P[n], P[m], n, m) for n in range(N, M) for m in range(n + 1, M) if (P[n] - P[m]) % gcd(n, m) == 0))
