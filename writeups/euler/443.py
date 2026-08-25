import math
import sympy


def solve_pe443_sympy(target=10**15):
    n = 4
    g = 13
    while n < target:
        D = g - n
        k = D - 1
        # Phân tích thừa số nguyên tố của k = D - 1
        p_factors = sympy.primefactors(k)

        # Tìm điểm nhảy tiếp theo (bội số nhỏ nhất của một trong các p > n)
        next_n = min(((n // p) + 1) * p for p in p_factors)

        if next_n > target:
            g += target - n
            break

        # Nhảy thẳng tới trước next_n, sau đó thực hiện 1 bước GCD
        g += next_n - 1 - n
        n = next_n - 1

        n += 1
        g += math.gcd(n, k)

    return g


print("Result:", solve_pe443_sympy(10**15))
