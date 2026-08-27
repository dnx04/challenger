from functools import cache

a = 21**7
b = 7**21
c = 12**7

@cache
def f(n):
    if n > b:
        return n - c
    return f(a + f(a + f(a + f(a + n))))

def f_closed(n):
    if n > b:
        return n - c
    return n + 4 * (a - c) + (4 * a - 3 * c) * ((b - n) // a)


def sum_f():
    q, r = divmod(b, a)
    # sum_{m=0}^{b} floor(m / a)
    s_floor = a * q * (q - 1) // 2 + (r + 1) * q
    return b * (b + 1) // 2 + (b + 1) * 4 * (a - c) + (4 * a - 3 * c) * s_floor


print(sum_f() % 10**9)
