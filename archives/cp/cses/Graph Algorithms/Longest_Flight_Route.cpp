#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
  }
  vector<int> dp(n, -1), nex(n, -1);
  auto dfs = [&](auto dfs, int u, int p) -> int {
    if (dp[u] != -1) return dp[u];
    if (u == n - 1) return dp[u] = n;
    for (int v : g[u]) {
      if (v == p) continue;
      dfs(dfs, v, u);
      if (dp[u] < dp[v] + 1) dp[u] = dp[v] + 1, nex[u] = v;
    }
    return dp[u];
  };
  dfs(dfs, 0, 0);
  vector<int> ans;
  for (int u = 0; u != -1; u = nex[u]) ans.push_back(u);
  if (ans.back() == n - 1) {
    cout << ans.size() << '\n';
    for (auto u : ans) cout << u + 1 << ' ';
  } else {
    cout << "IMPOSSIBLE";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}