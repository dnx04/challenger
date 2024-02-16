#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<int> a(n), par(n), mx(n);
  vector<ll> ans(n), fin(n);
  vector<unordered_map<int, int>> cnt(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  iota(begin(par), end(par), 0);
  auto root = [&](auto root, int u) {
    if (par[u] == u) return u;
    return par[u] = root(root, par[u]);
  };
  auto merge = [&](int u, int v) {
    if ((u = root(root, u)) == (v = root(root, v))) return;
    if (cnt[u].size() < cnt[v].size()) swap(u, v);
    for (auto [x, y] : cnt[v]) {
      cnt[u][x] += y;
      if (cnt[u][x] > mx[u])
        ans[u] = x, mx[u] = cnt[u][x];
      else if (cnt[u][x] == mx[u])
        ans[u] += x;
    }
    par[v] = u;
    cnt[v].clear();
  };
  auto dfs = [&](auto dfs, int u, int p) -> void {
    ++cnt[u][a[u]];
    mx[u] = 1, ans[u] = a[u];
    for (auto v : g[u]) {
      if (v != p) {
        dfs(dfs, v, u);
        merge(u, v);
      }
    }
    fin[u] = ans[root(root, u)];
  };
  dfs(dfs, 0, 0);
  for (int i = 0; i < n; ++i) cout << fin[i] << ' ';
}