#line 1 "Nested_Ranges_Check.cpp"
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
#line 9 "Nested_Ranges_Check.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<tuple<int, int, int>> a(n);
  vector<int> idx;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[i] = {x, y, i};
    idx.push_back(x), idx.push_back(y);
  }

  // this is how you compress pair correctly
  sort(idx.begin(), idx.end());
  idx.resize(unique(idx.begin(), idx.end()) - idx.begin());
  for (auto &[x, y, i] : a) {
    x = lower_bound(idx.begin(), idx.end(), x) - idx.begin();
    y = lower_bound(idx.begin(), idx.end(), y) - idx.begin();
  }
  vector<int> in(n), out(n);
  int sz = idx.size();
  fenwick_tree<int> ft(sz);

  // find the number of ranges that contain x
  sort(begin(a), end(a), [&](auto &a, auto &b) {
    if (get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
    return get<0>(a) < get<0>(b);
  });
  for (auto [x, y, i] : a) {
    in[i] = ft.sum(y, sz);
    ft.add(y, 1);
  }
  // find the number of ranges that x contains
  sort(begin(a), end(a), [&](auto &a, auto &b) {
    if (get<1>(a) == get<1>(b)) return get<0>(a) > get<0>(b);
    return get<1>(a) < get<1>(b);
  });
  ft = fenwick_tree<int>(sz);
  for (auto [x, y, i] : a) {
    out[i] = ft.sum(x, y);
    ft.add(x, 1);
  }
  for (auto res : out) cout << (res ? 1 : 0) << ' ';
  cout << '\n';
  for (auto res : in) cout << (res ? 1 : 0) << ' ';
}
