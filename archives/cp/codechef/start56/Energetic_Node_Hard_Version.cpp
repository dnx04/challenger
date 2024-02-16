#line 1 "Energetic_Node_Hard_Version.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 1 "algo/data-structure/fenwick.hpp"
template <typename T>
struct fenwick_tree {
  fenwick_tree(int _n) : n(_n), f(_n + 1) {}

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
#line 9 "Energetic_Node_Hard_Version.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<int> up(n + 1), c(n + 1);
  vector<vector<int>> g(n + 1);
  for (int i = 1; i <= n; ++i) cin >> up[i];
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    if (up[i] == 1) {
      ++c[i];
      for (auto j : g[i]) ++c[j];
    }
  }
  int q;
  cin >> q;
  vector<vector<tuple<int, int, ll>>> query(n + 1);
  vector<ll> ans(q);
  fenwick_tree<ll> cnt_c(n + 1);
  for (int i = 0; i < q; ++i) {
    int x, t;
    ll k;
    cin >> x >> t >> k;
    query[x].push_back({i, t, k});
  }
  const auto MAX = 2e9;
  auto process = [&](int idx, int t, ll k) -> void {
    ll l = 1, r = MAX, res = r;
    while (l <= r) {
      ll mid = (l + r) >> 1, idx = k / (mid * (mid + 1) / 2);
      if (k % (mid * (mid + 1) / 2) > 0) ++idx;
      idx = min(idx, 1ll * n);
      if (cnt_c.sum(idx, n + 1) >= t) {
        res = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    ans[idx] = (res == MAX ? -1 : res);
  };
  auto dfs = [&](auto dfs, int u, int p) -> void {
    if (c[u]) cnt_c.add(c[u], 1);
    for (auto [idx, t, k] : query[u]) process(idx, t, k);
    for (auto v : g[u]) {
      if (v != p) {
        dfs(dfs, v, u);
      }
    }
    if (c[u]) cnt_c.add(c[u], -1);
  };
  dfs(dfs, 1, 1);
  for (auto val : ans) cout << val << '\n';
}
