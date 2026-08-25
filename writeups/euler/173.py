from math import isqrt

ans = 0

# a^2 - b^2 <= 1e6, b < a, a^2 <= b^2 + 1e6

for b in range(1, 250000):
    ans += (isqrt(b * b + 10**6) - b) // 2

print(ans)
