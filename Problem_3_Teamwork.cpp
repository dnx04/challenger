#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("teamwork.in", "r", stdin);
  freopen("teamwork.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), dp(n);
  for (auto &v : a) cin >> v;
  for (int i = 0; i < n; ++i) {
    int cur = a[i];
    for (int j = i; j >= (i - k + 1) && ~j; --j) {  // j >= 0
      cur = max(cur, a[j]);
      if (j)
        dp[i] = max(dp[i], dp[j - 1] + cur * (i - j + 1));
      else
        dp[i] = max(dp[i], cur * (i - j + 1));
    }
  }
  cout << dp[n - 1];
}