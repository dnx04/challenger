#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

const int N = 1001;
vector<int> g[N], val(N);

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("time.in", "r", stdin);
  freopen("time.out", "w", stdout);
  int n, m, c;
  cin >> n >> m >> c;
  vector<vector<long long>> dp(N, vector<long long>(N, -1e18));
  for (int i = 1; i <= n; ++i) cin >> val[i];
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }
  queue<tuple<int, int, long long>> q;
  q.push({1, 0, 0});
  dp[1][0] = 0;
  while (!q.empty()) {
    auto [u, len, value] = q.front();
    q.pop();
    if (len + 1 < N && dp[u][len] == value) {
      for (auto v : g[u]) {
        if (dp[v][len + 1] < dp[u][len] + val[v] - c * (2 * len + 1)) {
          dp[v][len + 1] =
              max(dp[v][len + 1], dp[u][len] + val[v] - c * (2 * len + 1));
          q.push({v, len + 1, dp[v][len + 1]});
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < N; ++i) ans = max(ans, dp[1][i]);
  cout << ans;
}