from collections import deque


def smallest_multiple(n):
    parent = {}
    q = deque()
    for d in (1, 2):
        r = d % n
        if r not in parent:
            parent[r] = (None, d)
            q.append(r)
    while q:
        r = q.popleft()
        if r == 0:
            break
        for d in (0, 1, 2):
            nr = (r * 10 + d) % n
            if nr not in parent:
                parent[nr] = (r, d)
                q.append(nr)
    digits = []
    r = 0
    while r is not None:
        r, d = parent[r]
        digits.append(d)
    return int("".join(str(d) for d in reversed(digits)))


def solve(limit=10000):
    return sum(smallest_multiple(n) // n for n in range(1, limit + 1))


if __name__ == "__main__":
    print(solve())
