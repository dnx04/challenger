#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  using ld = long double;
  int n, a, b;
  cin >> n >> a >> b;
  vector<vector<ld>> dp(n + 1, vector<ld>(n * 6 + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6 * n; ++j) {
      for (int k = 1; k <= 6; ++k) {
        if (j >= k) dp[i][j] += dp[i - 1][j - k] / 6;
      }
    }
  }
  ld ans = 0;
  for (int i = a; i <= b; ++i) ans += dp[n][i];
  cout << fixed << setprecision(6) << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}