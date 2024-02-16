#line 1 "F_SUM_and_REPLACE.cpp"
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
#line 9 "F_SUM_and_REPLACE.cpp"

const int N = 1e6 + 1;
vector<int> d(N);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      ++d[j];
    }
  }
  int n, q;
  cin >> n >> q;
  set<int> idx;
  for (int i = 0; i < n; ++i) {
    idx.insert(i);
  }
  fenwick_tree<ll> ft(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ft.add(i, x);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      --l, --r;
      auto itr = idx.lower_bound(l);
      while (itr != idx.end() && *itr <= r) {
        int i = *itr;
        ft.add(i, d[ft.sum(i, i + 1)] - ft.sum(i, i + 1));
        if (ft.sum(i, i + 1) < 3) {
          itr = idx.erase(itr);
        } else {
          ++itr;
        }
      }
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      cout << ft.sum(l, r + 1) << '\n';
    }
  }
}
