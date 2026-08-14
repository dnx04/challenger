def sum_v2_plus_1(K):
    """Tính tổng_{k=1}^K (v_2(k) + 1) trong O(log K)"""
    if K <= 0:
        return 0
    ans = K
    power = 2
    while power <= K:
        ans += K // power
        power *= 2
    return ans

def solve_pe561(N=10**12, m=904961):
    K1 = N // 4
    # Tổng cho các cặp (4k, 4k+1)
    total = (m + 1) * sum_v2_plus_1(K1)
    
    # Trường hợp phần dư nếu (N + 1) chia hết cho 4 (u = 4*K2 có nhưng 4*K2 + 1 chưa tới)
    if (N + 1) % 4 == 0:
        K2 = (N + 1) // 4
        # Lấy giá trị v2(K2)
        v2_K2 = 0
        temp = K2
        while temp % 2 == 0:
            v2_K2 += 1
            temp //= 2
        total += m * (v2_K2 + 1)
        
    return total

if __name__ == "__main__":
    N = 10**12
    m = 904961
    result = solve_pe561(N, m)
    print(f"Đáp số Q(10^12) cho PE 561 là: {result}")
