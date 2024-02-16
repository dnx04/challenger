#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  const ll INF = 1e18;
  int m, n;
  cin >> n >> m;
  vector<ll> a(n + 1, -INF), dp(n + 1, -INF), ndp(n + 1, -INF);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  dp = a;
  for (int t = 2; t <= m; ++t) {
    for (int i = t; i <= n; ++i) {
      ndp[i] = max(ndp[i], t * a[i] + dp[i - 1]);
      dp[i] = max(dp[i], dp[i - 1]);
    }
    dp = ndp;
    fill(begin(ndp), end(ndp), -INF);
  }
  cout << *max_element(begin(dp), end(dp));
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}