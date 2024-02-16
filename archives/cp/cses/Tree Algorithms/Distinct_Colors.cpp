#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<int> c(n), ans(n);
  vector<set<int>> dp(n);
  for (auto &v : c) cin >> v;
  for (int i = 0; i < n; ++i) dp[i].insert(c[i]);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto dfs = [&](auto dfs, int u, int p) -> void {
    for (auto v : g[u]) {
      if (v != p) {
        dfs(dfs, v, u);
        if (dp[v].size() > dp[u].size()) swap(dp[u], dp[v]);
        for (auto x : dp[v]) dp[u].insert(x);
        dp[v].clear();
      }
    }
    ans[u] = dp[u].size();
  };
  dfs(dfs, 0, 0);
  for (auto v : ans) cout << v << ' ';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}