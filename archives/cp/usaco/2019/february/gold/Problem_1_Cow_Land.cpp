#line 1 "Problem_1_Cow_Land.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 1 "algo/data-structure/fenwick.hpp"
template <typename T>
struct fenwick_tree {
  fenwick_tree(int n) : n(n), f(n + 1) {}

  // a[u] ^= val
  void add(int u, T val) {
    assert(0 <= u && u < n);
    ++u;
    while (u <= n) {
      f[u] ^= val;
      u += u & -u;
    }
  }

  // return the sum of [0, u)
  T sum(int u) const {
    assert(0 <= u && u <= n);
    T res = 0;
    while (u) {
      res ^= f[u];
      u -= u & -u;
    }
    return res;
  }

  // return the sum of [l, r)
  T sum(int l, int r) const {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return 0;
    return sum(r) ^ sum(l);
  }

  void reset() { fill(f.begin(), f.end(), T(0)); }

  int n;
  vector<T> f;
};
#line 2 "algo/tree/lca.hpp"

struct lca {
  int n, l;
  vector<int> in, out;
  vector<vector<int>> up;
  lca(const vector<vector<int>> &g, int root)
      : n(g.size()), l(__lg(n) + 1), in(n), out(n), up(n, vector<int>(l)) {
    int timer = 0;
    auto dfs = [&](auto dfs, int p, int u) -> void {
      in[u] = timer++;
      up[u][0] = p;
      for (int i = 1; i < l; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
      }
      for (auto v : g[u])
        if (v != p) dfs(dfs, u, v);
      out[u] = timer++;
    };
    dfs(dfs, root, root);
  };
  bool is_anc(int u, int v) const { return in[u] <= in[v] && out[u] >= out[v]; }
  int get(int u, int v) const {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = l - 1; i >= 0; --i) {
      if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
  }
};
#line 10 "Problem_1_Cow_Land.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  freopen("cowland.in", "r", stdin);
  freopen("cowland.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> in(n), out(n);
  auto dfs = [&](auto dfs, int u, int p) -> void {
    static int t = 0;
    in[u] = t++;
    for (int v : g[u]) {
      if (v == p) continue;
      dfs(dfs, v, u);
    }
    out[u] = t;
  };
  dfs(dfs, 0, 0);

  fenwick_tree<int> fw(n);
  auto lca_tree = lca(g, 0);
  for (int i = 0; i < n; ++i) {
    fw.add(in[i], a[i]);
    if (out[i] < n) fw.add(out[i], a[i]);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, x;
      cin >> u >> x;
      --u;
      fw.add(in[u], a[u] ^ x);
      if(out[u] < n) fw.add(out[u], a[u] ^ x);
      a[u] = x;
    } else {
      int x, y;
      cin >> x >> y;
      --x, --y;
      int z = lca_tree.get(x, y);
      int res = fw.sum(in[x] + 1) ^ fw.sum(in[y] + 1) ^ a[z];
      cout << res << '\n';
    }
  }
}
