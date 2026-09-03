def solve_prime_guessing(N):
    # 1. Fast Sieve of Eratosthenes to find all primes <= N
    sieve = bytearray([True]) * (N // 2)
    for i in range(3, int(N**0.5) + 1, 2):
        if sieve[i // 2]:
            sieve[i*i // 2::i] = bytearray([False]) * ((N - i*i - 1) // (2 * i) + 1)
    
    # Construct the prime list (including 2)
    primes = [2] + [2 * i + 1 for i in range(1, N // 2) if sieve[i]]
    total_primes = len(primes)
    
    # 2. Recursive function to find the maximum possible points at each bit depth
    def get_max_points(P, depth):
        if not P:
            return 0
        
        limit = 1 << depth
        
        # Filter primes that are long enough to have a bit at the current depth
        P_cont = [p for p in P if p >= limit]
        if not P_cont:
            return 0
            
        P0 = []
        P1 = []
        
        # Partition based on the value of the `depth`-th bit
        for p in P_cont:
            if (p >> depth) & 1:
                P1.append(p)
            else:
                P0.append(p)
                
        # The player optimally chooses the bit that yields the most correct guesses
        score = max(len(P0), len(P1))
        
        # Traverse down the sub-trees for the next bit
        return score + get_max_points(P0, depth + 1) + get_max_points(P1, depth + 1)

    # 3. Compute expectation
    total_points = get_max_points(primes, 0)
    expected_value = total_points / total_primes
    
    return expected_value

# Output the answer rounded to 8 decimal places as requested
E_10_8 = solve_prime_guessing(30)
print(f"{E_10_8:.8f}")
