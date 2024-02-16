#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  const ll MAX = 1e18;
  int n;
  cin >> n;
  vector<int> a(n + 1), srt(n + 1);
  vector<ll> dp(n + 1), ndp(n + 1, MAX);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  srt = a;
  sort(srt.begin(), srt.end());

  // dp(i, j) = min(dp(i - 1, k <= j)) + abs(a[i] - srt[j])
  // dimension reduction applied
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ndp[j] = dp[j] + abs(a[i] - srt[j]);
    }
    dp = ndp;
    for (int i = 2; i <= n; ++i) dp[i] = min(dp[i - 1], dp[i]);
    ndp = vector<ll>(n + 1, MAX);
  }
  cout << dp[n];
}