#line 1 "Forest_Queries_II.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 1 "algo/data-structure/fenwick.hpp"
template <typename T>
struct fenwick {
  fenwick(int n) : n(n), f(n + 1) {}

  // a[u] += val
  void add(int u, T val) {
    assert(0 <= u && u < n);
    ++u;
    while (u <= n) f[u] += val, u += u & -u;
  }

  // return the sum of [0, u)
  T sum(int u) const {
    assert(0 <= u && u <= n);
    T res = 0;
    while (u) res += f[u], u -= u & -u;
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
#line 2 "algo/data-structure/fenwick2d.hpp"

template <class T>
struct fenwick2d {
  int n, m;
  vector<fenwick<T>> f;
  fenwick2d(int n, int m) : n(n), m(m), f(n + 1, fenwick<T>(m)) {}
  void add(int x, int y, T v) {
    assert(0 <= x && x < n && 0 <= y && y < m);
    ++x;
    while (x <= n) f[x].add(y, v), x += x & -x;
  }
  // add v to [0, x) * [0, y)
  void add(int x1, int y1, int x2, int y2, T v) {
    add(x1, y1, v);
    add(x1, y2 + 1, -v);
    add(x2 + 1, y1, -v);
    add(x2 + 1, y2 + 1, v);
  }
  // sum of [0, x) * [0, y)
  T sum(int x, int y) {
    T res = 0;
    while(x) res += f[x].sum(y), x -= x & -x;
    return res;
  }
  // sum of [x1, x2) * [y1, y2)
  T sum(int x1, int y1, int x2, int y2) {
    return sum(x2, y2) - sum(x1, y2) - sum(x2, y1) + sum(x1, y1);
  }
};
#line 9 "Forest_Queries_II.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  fenwick2d<int> f(n, n);
  vector<string> s(n);
  for(int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      f.add(i, j, s[i][j] == '*');
    }
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, y;
      cin >> x >> y;
      --x, --y;
      f.add(x, y, (s[x][y] == '*') ? -1 : 1);
      s[x][y] = (s[x][y] == '*') ? '.' : '*';
    } else {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      --x1, --y1, --x2, --y2;
      cout << f.sum(x1, y1, x2 + 1, y2 + 1) << '\n';
    }
  }
}