#line 1 "C_-_Swaps_2.cpp"
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
#line 9 "C_-_Swaps_2.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  map<int, vector<int>> id_a, id_b;
  for (int i = 0; i < n; ++i) cin >> a[i], a[i] += i, id_a[a[i]].push_back(i);
  for (int i = 0; i < n; ++i) cin >> b[i], b[i] += i, id_b[b[i]].push_back(i);
  bool ok = true;
  for (auto [k, _] : id_a) {
    ok &= id_a[k].size() == id_b[k].size();
    if (!ok) break;
  }
  if (!ok) {
    cout << -1;
  } else {
    for (auto [k, pos] : id_a) {
      int sz = pos.size();
      for (int i = 0; i < sz; ++i) {
        int x = pos[i], y = id_b[k][i];
        c[x] = y;
      }
    }
    fenwick_tree<int> fw(n + 1);
    ll ans = 0;
    for(int i = 0; i < n; ++i) ans += fw.sum(c[i] + 1, n + 1), fw.add(c[i], 1);
    cout << ans;
  }
}
