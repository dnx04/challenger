def nde2pq(N, d, e):
    k = d * e - 1
    while True:
        g = randint(2, N - 1)
        while True:
            x = pow(g, k, N)
            if x > 1:
                y = gcd(x - 1, N)
                if y > 1:
                    p = y
                    q = N // y
                    return p, q
            k //= 2
