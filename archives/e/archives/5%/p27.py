from sage.all import *


def p27():
    max_cnt, ans = 0, 0
    for a in range(-1000, 1000):
        for b in range(-1000, 1001):
            n = 0
            while is_prime(n * n + a * n + b):
                n += 1
            if n > max_cnt:
                max_cnt, ans = n, a * b
    return ans


if __name__ == '__main__':
    print(p27())
