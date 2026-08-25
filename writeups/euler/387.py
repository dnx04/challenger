L = 10^14

level, total = [(n, n) for n in srange(1, 10)], 0
while level:
    total += sum(10*n + d for n, s in level if is_prime(n // s)
                 for d in (1, 3, 7, 9) if is_prime(10*n + d))
    level = [(10*n + d, s + d) for n, s in level for d in srange(10)
             if 10*n + d < L // 10 and (10*n + d) % (s + d) == 0]

print(total)
