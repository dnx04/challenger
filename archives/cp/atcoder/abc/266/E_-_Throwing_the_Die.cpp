#include <bits/extc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  const int N = 101;
  vector<double> dp(N);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (double j = 1; j <= 6; ++j) {
      dp[i] += max(j, dp[i - 1]);
    }
    dp[i] /= 6;
  }
  cout << fixed << setprecision(10) << dp[n];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}