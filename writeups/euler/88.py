def factorizations(n, min_factor=2):
    # Trả về chính n (trường hợp 1 thừa số)
    yield [n]
    
    for i in range(min_factor, int(n**0.5) + 1):
        if n % i == 0:
            for sub in factorizations(n // i, i):
                yield [i] + sub

cnt = [1e9]  * 12001

for i in range(4, 100000):
    for factors in factorizations(i):
        gap = i - sum(factors)
        if 2 <= gap + len(factors) <= 12000:
            cnt[gap + len(factors)] = min(cnt[gap + len(factors)], i)

print(sum(set(cnt[2:])))
