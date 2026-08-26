#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MOD = 1e9;

signed main() {
  int n = 20;
  // cin >> n;
  pair<ll, ll> dp[n + 1][n * 81 + 1];
  memset(dp, 0, sizeof dp);
  dp[0][0] = {1, 0};
  for(int i = 0; i < n; ++i) {
    for(int d = 0; d < 10; ++d) {
      for(int sum = 0; sum + d * d < n * 81 + 1; ++sum) {
        dp[i + 1][sum + d * d].first += dp[i][sum].first;
        dp[i + 1][sum + d * d].second += dp[i][sum].second * 10 + dp[i][sum].first * d;
        dp[i + 1][sum + d * d].second %= MOD;
      }
    }
  }
  ll ans = 0;
  for(int i = 0; i * i < n * 81 + 1; ++i) {
    ans += dp[n][i * i].second;
    ans %= MOD;
  }
  cout << ans;
}
