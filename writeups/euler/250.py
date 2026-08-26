MOD = 10 ** 16
LIMIT = 250250
K = 250


def solve(limit=LIMIT, k=K, mod=MOD):
    counts = [0] * k
    counts[0] = 1
    for i in range(1, limit + 1):
        a = pow(i, i, k)
        if a == 0:
            counts = [(c + c) % mod for c in counts]
        else:
            counts = [(counts[r] + counts[r - a]) % mod for r in range(k)]
    return (counts[0] - 1) % mod


if __name__ == "__main__":
    print(solve())
