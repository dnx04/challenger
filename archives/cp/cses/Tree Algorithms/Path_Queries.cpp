#line 1 "Path_Queries.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 1 "algo/data-structure/fenwick.hpp"
template <typename T>
struct fenwick_tree {
  fenwick_tree(int n) : n(n), f(n + 1) {}

  // a[u] += val
  void add(int u, T val) {
    assert(0 <= u && u < n);
    ++u;
    while (u <= n) {
      f[u] += val;
      u += u & -u;
    }
  }

  // return the sum of [0, u)
  T sum(int u) const {
    assert(0 <= u && u <= n);
    T res = 0;
    while (u) {
      res += f[u];
      u -= u & -u;
    }
    return res;
  }

  // return the sum of [l, r)
  T sum(int l, int r) const {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return 0;
    return sum(r) - sum(l);
  }

  void reset() { fill(f.begin(), f.end(), T(0)); }

  int n;
  vector<T> f;
};
#line 9 "Path_Queries.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
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
  vector<int> ord;
  vector<int> in(n), out(n);
  auto dfs = [&](auto dfs, int p, int u) -> void {
    static int timer = 0;
    in[u] = timer++;
    ord.push_back(u);
    for (auto v : g[u])
      if (v != p) dfs(dfs, u, v);
    out[u] = timer;
  };
  dfs(dfs, 0, 0);
  fenwick_tree<ll> fw(n);
  for (int i = 0; i < n; ++i) {
    fw.add(in[i], a[i]);
    if (out[i] < n) fw.add(out[i], -a[i]);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, x;
      cin >> u >> x;
      --u;
      fw.add(in[u], x - a[u]);
      if (out[u] < n) fw.add(out[u], a[u] - x);
      a[u] = x;
    } else {
      int u;
      cin >> u;
      --u;
      cout << fw.sum(in[u] + 1) << '\n';
    }
  }
}
