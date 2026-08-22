def solve_pe297(N):
    # Generate Fibonacci numbers F_1 = 1, F_2 = 2, F_3 = 3, ...
    fibs = [1, 2]
    while True:
        nxt = fibs[-1] + fibs[-2]
        if nxt > N:
            break
        fibs.append(nxt)
    
    # Precompute S(F_k)
    # S(F_1) = S(1) = 0
    # S(F_2) = S(2) = 1
    # S(F_k) = S(F_{k-1}) + S(F_{k-2}) + F_{k-2}
    S_fib = {1: 0, 2: 1}
    for i in range(3, len(fibs) + 1):
        # fibs is 0-indexed so F_k is fibs[k-1]
        # F_{k-2} is fibs[k-3]
        S_fib[i] = S_fib[i-1] + S_fib[i-2] + fibs[i-3]
    
    # Map fib value to index k
    fib_map = {f: i+1 for i, f in enumerate(fibs)}
    
    # Decompose N into Zeckendorf representation
    temp = N
    terms = []
    for f in reversed(fibs):
        if f <= temp:
            terms.append(f)
            temp -= f
        if temp == 0:
            break
            
    # Calculate S(N)
    total_sum = 0
    prefix_count = 0
    for f in terms:
        k = fib_map[f]
        total_sum += prefix_count * f + S_fib[k]
        prefix_count += 1
        
    return total_sum

ans = solve_pe297(10**17)
print(f"Answer: {ans}")
