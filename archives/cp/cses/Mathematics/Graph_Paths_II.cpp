#line 1 "Graph_Paths_II.cpp"
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

const long long INF = 2e18;

#line 1 "algo/math/matrix.hpp"
template <typename T>
struct matrix {
  int n_row, n_col;
  vector<T> x;

  // accessors
  typename vector<T>::iterator operator[](int r) {
    return x.begin() + r * n_col;
  }
  inline T get(int i, int j) const { return x[i * n_col + j]; }

  // constructors
  matrix() = default;
  matrix(int n_row, int n_col, T val = 0)
      : n_row(n_row), n_col(n_col), x(n_row * n_col, val) {}
  matrix(const vector<vector<T>>& d)
      : n_row(d.size()), n_col(d.size() ? d[0].size() : 0) {
    for (auto& row : d) copy(row.begin(), row.end(), back_inserter(x));
  }

  // convert to 2d vec
  vector<vector<T>> vecvec() const {
    vector<vector<T>> ret(n_row);
    for (int i = 0; i < n_row; i++) {
      copy(x.begin() + i * n_col, x.begin() + (i + 1) * n_col,
           back_inserter(ret[i]));
    }
    return ret;
  }
  operator vector<vector<T>>() const { return vecvec(); }

  static matrix identity(int n) {
    matrix res(n, n);
    for (int i = 0; i < n; i++) {
      res[i][i] = 1;
    }
    return res;
  }

  matrix transpose() const {
    matrix res(n_col, n_row);
    for (int i = 0; i < n_row; i++) {
      for (int j = 0; j < n_col; j++) {
        res[j][i] = this->get(i, j);
      }
    }
    return res;
  }

  matrix& operator*=(const matrix& r) { return *this = *this * r; }
  matrix operator*(const matrix& r) const {
    assert(n_col == r.n_row);
    matrix res(n_row, r.n_col, INF);

    for (int i = 0; i < n_row; i++) {
      for (int j = 0; j < r.n_col; j++) {
        for (int k = 0; k < n_col; k++) {
          res[i][j] = min(res[i][j], this->get(i, k) + r.get(k, j));
        }
      }
    }
    return res;
  }

  matrix operator^(long long n) const {
    assert(n_row == n_col);
    if (n == 0) return identity(n_row);
    if (n == 1) return *this;
    matrix res = *this ^ (n >> 1);
    res = res * res;
    if (n & 1) res = res * *this;
    return res;
  }
};
#line 8 "Graph_Paths_II.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m, k;
  cin >> n >> m >> k;
  matrix<long long> d(n, n, INF);
  for (int i = 0; i < m; ++i) {
    int u, v;
    long long w;
    cin >> u >> v >> w;
    --u, --v;
    d[u][v] = min(d[u][v], w);
  }
  long long ans = (d ^ k)[0][n - 1];
  cout << (ans == INF ? -1 : ans);
}
