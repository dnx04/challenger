#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  const ll INF = 1e18;
  ll ans = INF;
  vector<ll> dp(n + 1, INF);
  dp[1] = dp[2] = a[1];
  for (int i = 3; i <= n; ++i) {
    dp[i] = min(dp[i - 1], dp[i - 2]) + a[i - 1];
  }
  cerr << dp[n] << '\n';
  ans = min(ans, dp[n]);
  fill(begin(dp), end(dp), INF);
  dp[1] = a[n];
  for (int i = 2; i < n; ++i) {
    dp[i] = min(dp[i - 1], dp[i - 2]) + a[i - 1];
  }
  ans = min({ans, dp[n - 1], dp[n - 2] + a[n - 1]});
  cout << ans;
}