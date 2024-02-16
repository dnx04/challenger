#line 1 "F_-_Exactly_K_Steps.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 1 "algo/graph/tree_diameter.hpp"
pair<ll, vector<int>> get_diameter(const vector<vector<pair<int, int>>>& g) {
  int n = g.size();
  vector<ll> dist(n);
  vector<int> parent(n);

  auto dfs = [&](auto self, int u, int fu, ll cur_dist) -> void {
    dist[u] = cur_dist;
    parent[u] = fu;
    for (auto [v, cost] : g[u])
      if (v != fu) {
        self(self, v, u, cur_dist + cost);
      }
  };
  dfs(dfs, 0, -1, 0);
  // r = furthest node from root
  int r = max_element(dist.begin(), dist.end()) - dist.begin();
  dfs(dfs, r, -1, 0);
  // r->s = longest path
  int s = max_element(dist.begin(), dist.end()) - dist.begin();

  vector<int> path;
  for (int x = s; x >= 0; x = parent[x]) path.push_back(x);

  return {dist[s], path};
}
#line 9 "F_-_Exactly_K_Steps.cpp"

void solve([[maybe_unused]] int ith) {
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back({v, 1}), g[v].push_back({u, 1});
  }
  vector<vector<pair<int, int>>> qv(n);
  int q;
  cin >> q;
  vector<int> ans(q, -1);
  for (int i = 0; i < q; ++i) {
    int u, k;
    cin >> u >> k;
    qv[--u].push_back({i, k});
  }
  auto [d, path] = get_diameter(g);
  auto dfs = [&](auto self, int u, int p) -> void {
    static vector<int> order;
    for (const auto &[q, k] : qv[u]) {
      if (k <= (int)order.size()) ans[q] = order[(int)order.size() - k] + 1;
    }
    order.push_back(u);
    for (auto [v, w] : g[u]) {
      if (v == p) continue;
      self(self, v, u);
    }
    order.pop_back();
  };
  dfs(dfs, path[0], path[0]);
  dfs(dfs, path.back(), path.back());
  for(auto v: ans) cout << v << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}
