# f(i, j) = f(i - 1, j - 1) * 1 / i + f(i - 1, j) * (i - 1) / i

from sage.all import *

turns = 15

dp = matrix(QQ, turns + 1, turns + 1)
dp[0, 0] = 1

for i in range(0, turns):
    for j in range(i + 1):
        dp[i + 1, j] += dp[i, j] * (i + 1) / (i + 2)
        dp[i + 1, j + 1] += dp[i, j] * 1 / (i + 2)

ans = sum(dp[15, i] for i in range(8, 16))
print(ans.denominator() // ans.numerator())
