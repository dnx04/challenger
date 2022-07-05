from sage.all import *


def p41():
    ans = Permutation([7, 6, 5, 4, 3, 2, 1])
    while True:
        tmp = 0
        for digit in ans:
            tmp = tmp * 10 + digit
        if is_prime(tmp):
            return tmp
        ans = ans.prev()


if __name__ == '__main__':
    print(p41())
