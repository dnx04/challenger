#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, k;
  cin >> n >> k;
  vector<int> dp(n + 1, 0), a(k);
  for (int &x : a) cin >> x;
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int x : a) {
      if (x <= i) dp[i] = max(dp[i], x - dp[i - x]);
    }
  }
  cout << (n + dp[n]) / 2;
}