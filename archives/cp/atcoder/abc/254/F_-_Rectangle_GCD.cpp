#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

const int N = 2e5 + 1, K = 18;

template <typename T>
struct sparse_table {
  int n, k;
  vector<vector<T>> st;
  T f(T x = 0, T y = 0) { return gcd(x, y); }
  sparse_table(const vector<T> &v)
      : n(v.size()), k(__lg(n) + 1), st(n, vector<T>(k)) {
    for (int i = 0; i < n; ++i) st[i][0] = f(v[i]);
    for (int j = 1; j < k; j++)
      for (int i = 0; i + (1 << j) <= n; ++i)
        st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
  };
  T query(int l, int r) {
    T sum = 0;
    for (int j = k - 1; j >= 0; --j) {
      if ((1 << j) <= r - l + 1) {
        sum = f(sum, st[l][j]);
        l += 1 << j;
      }
    }
    return sum;
  }
};

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> a(n), b(n), c(n - 1), d(n - 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i) c[i - 1] = a[i] - a[i - 1];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (i) d[i - 1] = b[i] - b[i - 1];
  }
  sparse_table<int> st1(c), st2(d);
  while (q--) {
    int r1, r2, c1, c2;
    cin >> r1 >> r2 >> c1 >> c2;
    --r1, --r2, --c1, --c2;
    int g = gcd(st1.query(r1, r2 - 1), st2.query(c1, c2 - 1));
    cout << gcd(a[r1] + b[c1], g) << '\n';
  }
}