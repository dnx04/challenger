from sage.all import *

def p48():
    mod = 10 ** 10
    return sum([pow(i, i, mod) for i in range(1, 1001)]) % mod

if __name__ == '__main__':
    print(p48())