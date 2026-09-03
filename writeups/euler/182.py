import math

def solve_183():
    total_sum = 0
    
    for n in range(5, 10001):
        # Find the optimal integer k closest to N/e
        k = round(n / math.e)
        
        # Reduce the denominator to its lowest terms
        denom = k // math.gcd(n, k)
        
        # Check if the denominator only contains prime factors 2 and 5
        while denom % 2 == 0:
            denom //= 2
        while denom % 5 == 0:
            denom //= 5
            
        # Add or subtract N based on the termination rule
        if denom == 1:
            total_sum -= n
        else:
            total_sum += n
            
    return total_sum

print(solve_183())
