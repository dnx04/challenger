def compute_S(n):
    total_sum = 0
    
    for k in range(1, n + 1):
        remainder = pow(10, n - 1, k)
        
        digit = (remainder * 10) // k
        total_sum += digit
        
    return total_sum


print("Kiểm tra S(7):", compute_S(7))  
print("Kiểm tra S(100):", compute_S(100)) 

n_target = 10**7
result = compute_S(n_target)
print(f"S(10^7) = {result}")
