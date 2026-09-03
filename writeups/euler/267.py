from math import comb

def solve():
    # 1. Determine minimum heads (h) needed to reach 1,000,000,000
    # From our derived optimal fraction formula: f = (3h - 1000) / 2000
    target_capital = 10**9
    total_tosses = 1000
    min_heads = 0
    
    for h in range(1, total_tosses + 1):
        f = (3 * h - total_tosses) / (2 * total_tosses)
        if f > 0:
            # Check if this h and optimal f combination yields at least 1 billion
            capital = ((1 + 2 * f) ** h) * ((1 - f) ** (total_tosses - h))
            if capital >= target_capital:
                min_heads = h
                break

    # 2. Calculate the exact probability of getting at least 'min_heads'
    # Prob = Sum of combinations (1000 choose i) for i from min_heads to 1000, divided by 2^1000
    favorable_outcomes = sum(comb(total_tosses, i) for i in range(min_heads, total_tosses + 1))
    total_outcomes = 2 ** total_tosses
    
    probability = favorable_outcomes / total_outcomes
    
    # Return formatted string rounded to 12 decimal places
    return f"{probability:.12f}"

print(solve())
