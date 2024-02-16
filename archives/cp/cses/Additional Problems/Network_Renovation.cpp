#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> leaf;
  auto dfs = [&](auto dfs, int u, int p) -> void {
    for (auto v : g[u]) {
      if (v != p) dfs(dfs, v, u);
    }
    if(g[u].size() == 1) leaf.push_back(u);
  };
  dfs(dfs, 0, 0);
  int k = leaf.size();
  if (k & 1) leaf.push_back(leaf[0]), ++k;
  cout << k / 2 << '\n';
  for (int i = 0; i < k / 2; ++i) {
    cout << leaf[i] + 1 << ' ' << leaf[i + k / 2] + 1 << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}