from sage.all import *

i = 1
step = 2
num, den = 0, 1
while True:
    for _ in range(4):
        i += step
        if is_prime(i):
            num += 1
        den += 1
    if num * 10 < den:
        print(step + 1)
        break

    step += 2
