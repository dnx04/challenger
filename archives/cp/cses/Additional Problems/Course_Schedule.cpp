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
  vector<int> ans, vis(n);
  auto dfs = [&](auto dfs, int u) -> void {
    vis[u] = true;
    for (auto v : g[u]) {
      if (!vis[v]) {
        dfs(dfs, v);
      }
    }
    ans.push_back(u);
  };
  for (int i = 0; i < n; ++i)
    if (!vis[i]) dfs(dfs, i);
  reverse(begin(ans), end(ans));
  vector<int> id(n);
  for (int i = 0; i < n; ++i) id[ans[i]] = i;
  for (int i = 0; i < n; ++i) {
    for (auto j : g[i]) {
      if (id[j] < id[i]) {
        cout << "IMPOSSIBLE";
        return;
      }
    }
  }
  for (auto i : ans) cout << i + 1 << ' ';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}