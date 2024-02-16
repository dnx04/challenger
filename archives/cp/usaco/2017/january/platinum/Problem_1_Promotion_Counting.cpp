#line 1 "Problem_1_Promotion_Counting.cpp"
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
#line 9 "Problem_1_Promotion_Counting.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first;
    p[i].second = i;
  }
  auto compress = [&](vector<pair<int, int>> &a) {
    vector<pair<int, int>> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    for (auto &x : a) x.first = lower_bound(b.begin(), b.end(), x) - b.begin();
  };
  compress(p);
  sort(begin(p), end(p));
  fenwick_tree<int> f(n);
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    g[x].push_back(i);
  }
  vector<int> in(n), out(n), ans(n);
  int timer = 0;
  auto dfs = [&](auto dfs, int u, int p) -> void {
    in[u] = timer++;
    for (auto v : g[u])
      if (v != p) dfs(dfs, v, u);
    out[u] = timer;
  };
  dfs(dfs, 0, 0);
  for (int i = n - 1; i >= 0; --i) {
    int x = p[i].second;
    ans[x] = f.sum(in[x], out[x]);
    f.add(in[x], 1);
  }
  for (int i = 0; i < n; ++i) cout << ans[i] << '\n';
}
