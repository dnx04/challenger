from sage.all import *

def probability_of_20(q):
    # dp[j] stores the probability of scoring exactly j points
    dp = [0.0] * 21
    dp[0] = 1.0  # Base case: 0 points with 0 shots
    
    # Iterate through each shot from distance 1 to 50
    for x in range(1, 51):
        p = 1.0 - float(x) / float(q)  # Probability of success
        
        # Update DP table backwards to use O(1) space per step
        for j in range(min(x, 20), 0, -1):
            dp[j] = dp[j] * (1.0 - p) + dp[j-1] * p
        dp[0] = dp[0] * (1.0 - p)
        
    return dp[20]

# Target probability is 2% (0.02)
# We find the root where probability_of_20(q) - 0.02 == 0
# The problem states q > 50, a safe upper bound is 100
q_solution = find_root(lambda q: probability_of_20(q) - 0.02, 52, 60)

# Print the result rounded to 10 decimal places
print(f"q = {q_solution:.10f}")
