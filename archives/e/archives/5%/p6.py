from sage.all import *

n = 100
print(n * n * (n + 1) * (n + 1) // 4 -
      sum([i ** 2 for i in range(1, n + 1)]))  # 25164150