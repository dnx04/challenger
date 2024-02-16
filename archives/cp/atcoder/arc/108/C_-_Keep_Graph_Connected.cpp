#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v;
    g[u].push_back({c, v}), g[v].push_back({c, u});
  }
  vector<int> ans(n);
  ans[0] = 1;
  auto dfs = [&](auto dfs, int u, int p) -> void {
    for (auto [c, v] : g[u]) {
      if (v == p) continue;
      if (ans[v] == 0) {
        ans[v] = (ans[u] == c ? (c + 1) % n + 1 : c);
        dfs(dfs, v, u);
      }
    }
  };
  dfs(dfs, 0, 0);
  for (auto c : ans) cout << c << '\n';
}