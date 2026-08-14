from sage.arith.misc import next_prime
from sage.all import *

p1 = 5
ans = 0
while p1 <= 10**6:
    p2 = next_prime(p1)
    x = -p1 * inverse_mod(10 ** len(str(p1)), p2) % p2
    num = x * 10 ** len(str(p1)) + p1
    if p1 < 20: 
        print(num)
    ans += num
    p1 = p2

print(ans)
