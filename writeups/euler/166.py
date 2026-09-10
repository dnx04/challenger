def solve_pe166_fast():
    count = 0
    for m in range(10):
        for n in range(10):
            for o in range(10):
                for p in range(10):
                    S = m + n + o + p
                    mn = m + n
                    mno = mn + o
                    two_m_plus_n = 2 * m + n
                    
                    for l in range(10):
                        # h range from a = h + l - m => 0 <= a <= 9 => m - l <= h <= 9 + m - l
                        min_h = max(0, m - l)
                        max_h = min(9, 9 + m - l)
                        if min_h > max_h:
                            continue
                            
                        for h in range(min_h, max_h + 1):
                            a = h + l - m
                            
                            # d = mno - h - l
                            d = mno - h - l
                            if not (0 <= d <= 9):
                                continue
                                
                            for k in range(10):
                                # f = 2m + n + o - h - k - l
                                f = mno + m - h - k - l
                                if not (0 <= f <= 9):
                                    continue
                                    
                                for j in range(10):
                                    i = S - j - k - l
                                    if not (0 <= i <= 9):
                                        continue
                                        
                                    e = j + k - h
                                    if not (0 <= e <= 9):
                                        continue
                                        
                                    g = h - j + l - m + p
                                    if not (0 <= g <= 9):
                                        continue
                                        
                                    c = j - k - l - h + two_m_plus_n
                                    if not (0 <= c <= 9):
                                        continue
                                        
                                    b = S - a - c - d
                                    if 0 <= b <= 9:
                                        count += 1
    return count

t0 = time.time()
res = solve_pe166_fast()
t1 = time.time()
print(f"Fast Result: {res}, Time: {t1-t0:.2f}s")
