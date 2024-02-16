#line 1 "Distance_Queries.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 2 "algo/tree/lca.hpp"

struct lca {
  int n, l;
  vector<int> in, out, depth;
  vector<vector<int>> up;
  lca(const vector<vector<int>> &g, int root)
      : n(g.size()),
        l(__lg(n) + 1),
        in(n),
        out(n),
        depth(n),
        up(n, vector<int>(l)) {
    int timer = 0;
    auto dfs = [&](auto dfs, int p, int u, int d = 0) -> void {
      in[u] = timer++;
      up[u][0] = p;
      depth[u] = d;
      for (int i = 1; i < l; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
      }
      for (auto v : g[u])
        if (v != p) dfs(dfs, u, v, d + 1);
      out[u] = timer++;
    };
    dfs(dfs, root, root);
  };
  bool is_anc(int u, int v) const { return in[u] <= in[v] && out[u] >= out[v]; }
  int dist(int u, int v) const {
    return depth[u] + depth[v] - 2 * depth[get(u, v)];
  }
  int get(int u, int v) const {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = l - 1; i >= 0; --i) {
      if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
  }
};
#line 9 "Distance_Queries.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto lca_tree = lca(g, 0);
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    cout << lca_tree.dist(u, v) << '\n';
  }
}
