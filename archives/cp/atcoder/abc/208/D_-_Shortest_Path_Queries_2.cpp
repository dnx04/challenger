#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  const int INF = 1e9;
  int n, m;
  cin >> n >> m;
  vector<vector<int>> dp(n, vector<int>(n, INF));
  for(int i = 0; i < n; ++i) dp[i][i] = 0;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    cin >> dp[u][v];
  }
  ll sum = 0;
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        if (dp[i][j] < INF) sum += dp[i][j];
      }
    }
  }
  cout << sum;
}