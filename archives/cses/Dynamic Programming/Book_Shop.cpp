#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> h(n), s(n), dp(x + 1), ndp(x + 1);
  for (auto &x : h) cin >> x;
  for (auto &x : s) cin >> x;

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= x; ++j) {
      ndp[j] = dp[j];
      if (j >= h[i]) ndp[j] = max(ndp[j], dp[j - h[i]] + s[i]);
    }
    dp = ndp;
  }
  cout << dp[x];
}