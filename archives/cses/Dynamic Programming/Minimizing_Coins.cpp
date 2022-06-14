#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> dp(x + 1, -1);
  vector<int> c(n);
  for (auto &v : c) cin >> v;
  dp[0] = 0;
  for (int i = 1; i <= x; ++i) {
    for (auto v : c) {
      if (i >= v && dp[i - v] != -1) {
        dp[i] = (dp[i] == -1 ? dp[i - v] + 1 : min(dp[i], dp[i - v] + 1));
      }
    }
  }
  cout << dp[x];
}