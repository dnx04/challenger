def solve():
    from sage.all import RealField, ZZ
    import math

    R = RealField(210)         # use ~210 bits of precision to be safe
    bound = ZZ(10**12)
    total = ZZ(0)

    # Helper to check if n is a perfect square quickly
    def is_perfect_square(m):
        r = int(math.isqrt(m))
        return (r*r == m)

    for n in range(1, 100001):
        # Skip perfect squares
        if is_perfect_square(n):
            continue

        x = R(n).sqrt()
        # print(x)
        # nearby_rational returns a fraction in simplest form,
        # with denominator <= bound, that is closest to x.
        best_approx = x.nearby_rational(max_denominator=bound)
        # print(best_approx)
        # Just to be certain it's reduced:

        total += best_approx.denominator()

    print(total)

solve()