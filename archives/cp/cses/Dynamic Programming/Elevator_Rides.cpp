#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  const int N = 20;
  int n, x;
  vector<int> w(N);
  cin >> n >> x;
  for (int i = 0; i < n; ++i) cin >> w[i];
  vector<pair<int, int>> dp(1 << N);
  dp[0] = {1, 0};
  for (int mask = 1; mask < (1 << n); ++mask) {
    dp[mask] = {n + 1, 0};
    for (int msk = mask; msk > 0; msk -= msk & -msk) {
      int now = __lg(msk & -msk);
      auto option = dp[mask ^ (1 << now)];
      if (option.second + w[now] <= x) {
        // put the current one to the last ride
        option.second += w[now];
      } else {
        // place a new ride
        ++option.first, option.second = w[now];
      }
      dp[mask] = min(dp[mask], option);
    }
  }
  cout << dp[(1 << n) - 1].first;
}