#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> id(n);
  auto dfs = [&](auto dfs, int u, int uid = 0) -> void {
    id[u] = uid + 1;
    for (int v : g[u]) {
      if (!id[v])
        dfs(dfs, v, uid ^ 1);
      else {
        if (id[v] == id[u]) {
          cout << "IMPOSSIBLE";
          exit(0);
        }
      }
    }
  };
  for(int i = 0; i < n; ++i) if(!id[i]) dfs(dfs, i);
  for(int i = 0; i < n; ++i) cout << id[i] << ' ';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}