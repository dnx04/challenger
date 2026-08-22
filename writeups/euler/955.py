from sage.all import *

x = 2
cnt = 1
idx = 0

while cnt < 70:
    f = divisors(4 * x * (x + 1))
    y = 10**36
    step = 0
    for d1 in f:
        d2 = 4 * x * (x + 1) // d1
        if (d1 + d2 - 2) % 4 == 0 and (abs(d2 - d1) - 2) % 4 == 0 and (d1 + d2 - 2) // 4 < y and (d1 + d2 - 2) // 4 != x:
            y = (d1 + d2 - 2) // 4
            step = (abs(d2 - d1) - 2) // 4
    x = y
    idx += step
    cnt += 1
    print(cnt, y * (y + 1) // 2, idx)
