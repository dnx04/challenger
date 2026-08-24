import math

def get_small_primes(limit):
    """Generates primes up to `limit` using Sieve of Eratosthenes."""
    sieve = bytearray(b'\x01') * (limit + 1)
    sieve[0] = sieve[1] = 0
    for i in range(2, math.isqrt(limit) + 1):
        if sieve[i]:
            sieve[i*i : limit + 1 : i] = b'\x00' * (((limit - i*i) // i) + 1)
    return [i for i, is_p in enumerate(sieve) if is_p]

def S(N, small_primes):
    """Computes S(N): the sum of prime triplet elements in row N."""
    r_min = N - 2
    r_max = N + 2

    # First value in row N-2 and last value in row N+2
    val_min = (r_min - 1) * r_min // 2 + 1
    val_max = r_max * (r_max + 1) // 2
    sz = val_max - val_min + 1

    # Segmented sieve array for [val_min, val_max]
    is_prime = bytearray(b'\x01') * sz

    limit = math.isqrt(val_max)
    for p in small_primes:
        if p > limit:
            break
        start = ((val_min + p - 1) // p) * p
        if start < p * p:
            start = p * p
        if start <= val_max:
            count = (val_max - start) // p + 1
            is_prime[start - val_min : sz : p] = b'\x00' * count

    # Pre-calculate starting index offsets for each row in `is_prime`
    row_offset = {r: (r - 1) * r // 2 + 1 - val_min for r in range(r_min, r_max + 1)}

    def get_prime_neighbors(r, c):
        """Returns list of (row, col) coordinates for prime neighbors of cell (r, c)."""
        neighbors = []
        for dr in (-1, 0, 1):
            nr = r + dr
            if nr < r_min or nr > r_max:
                continue
            nr_base = row_offset[nr]
            for dc in (-1, 0, 1):
                if dr == 0 and dc == 0:
                    continue
                nc = c + dc
                if 0 <= nc < nr:  # Valid column in row nr
                    if is_prime[nr_base + nc]:
                        neighbors.append((nr, nc))
        return neighbors

    def get_deg(r, c):
        """Returns the number of prime neighbors for cell (r, c)."""
        return len(get_prime_neighbors(r, c))

    ans = 0
    base_N = row_offset[N]

    # Check each prime cell in target row N
    for c in range(N):
        if is_prime[base_N + c]:
            p_neighbors = get_prime_neighbors(N, c)
            deg_p = len(p_neighbors)
            
            # Condition 1: p has at least 2 prime neighbors
            if deg_p >= 2:
                val = (N - 1) * N // 2 + 1 + c
                ans += val
            # Condition 2: p has 1 prime neighbor q, and q has at least 2 prime neighbors
            elif deg_p == 1:
                qr, qc = p_neighbors[0]
                if get_deg(qr, qc) >= 2:
                    val = (N - 1) * N // 2 + 1 + c
                    ans += val

    return ans

def main():
    # Maximum row needed is 7208785 + 2 = 7208787
    # Max value ~ 2.6 x 10^13, so sqrt(max_val) ~ 5.1 x 10^6
    print("Precomputing small primes...")
    small_primes = get_small_primes(5100000)

    # Solve for test cases
    print(f"S(8) = {S(8, small_primes)}")
    print(f"S(9) = {S(9, small_primes)}")

    # Solve for Problem 196 target rows
    row1 = 5678027
    row2 = 7208785

    print(f"Computing S({row1})...")
    s1 = S(row1, small_primes)

    print(f"Computing S({row2})...")
    s2 = S(row2, small_primes)

    total = s1 + s2
    print(f"\nS({row1}) + S({row2}) = {total}")

if __name__ == "__main__":
    main()
