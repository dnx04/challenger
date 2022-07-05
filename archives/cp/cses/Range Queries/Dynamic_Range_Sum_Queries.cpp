#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define _GLIBCXX_ASSERTIONS
#endif

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

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

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, q;
  cin >> n >> q;
  fenwick_tree<int64_t> fw(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    fw.add(i, x);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, u;
      cin >> k >> u;
      --k;
      int ele = fw.sum(k, k + 1);
      fw.add(k, u - ele);
    } else {
      int a, b;
      cin >> a >> b;
      --a, --b;
      cout << fw.sum(a, b + 1) << '\n';
    }
  }
}