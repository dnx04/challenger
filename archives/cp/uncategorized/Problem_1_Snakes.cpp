#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("snakes.in", "r", stdin);
  freopen("snakes.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  int dp[n + 1][k + 1], mx = 0, sum = 0;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    mx = max(mx, a[i]);
    dp[i][0] = mx * i;
    for (int j = 1; j <= k; ++j) {
      dp[i][j] = INT32_MAX;
      int sz = a[i];
      for (int c = i - 1; c >= 0; --c) {
        dp[i][j] = min(dp[i][j], dp[c][j - 1] + sz * (i - c));
        sz = max(sz, a[c]);
      }
    }
    sum += a[i];
  }
  cout << dp[n][k] - sum;
}