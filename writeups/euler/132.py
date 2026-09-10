from sage.all import *

def solve_project_euler_132():
    # Number of digits in the repunit
    k = 10**9
    factors = []
    
    # Iterate through primes using SageMath's built-in generator
    for p in Primes():
        # Check if p divides R(10^9) using modular exponentiation
        if power_mod(10, k, 9 * p) == 1:
            factors.append(p)
            
            # Stop once we have gathered the first 40 prime factors
            if len(factors) == 40:
                break
                
    print(f"First 40 prime factors: {factors}")
    print(f"Sum of prime factors: {sum(factors)}")

# Execute the function
solve_project_euler_132()
