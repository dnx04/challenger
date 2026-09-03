# Define the variable
var('r')

# Given values
n = 5000
target = -600000000000

# Closed-form expression for the arithmetic-geometric sum
s = (897 - (900 - 3*n) * r**n) / (1 - r) - 3 * r * (1 - r**(n-1)) / (1 - r)**2

# Find the root in a logical interval (e.g., between 1.001 and 1.01)
r_sol = find_root(s == target, 1.001, 1.01)

# Output the answer rounded to 12 decimal places
print(f"{r_sol:.12f}")

