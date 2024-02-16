#line 1 "Fibonacci_Numbers.cpp"
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

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
  matrix(int _n_row, int _n_col)
      : n_row(_n_row), n_col(_n_col), x(n_row * n_col) {}
  matrix(const vector<vector<T>>& d)
      : n_row(d.size()), n_col(d.size() ? d[0].size() : 0) {
    for (auto& row : d)
      copy(row.begin(), row.end(), back_inserter(x));
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
    matrix res(n_row, r.n_col);

    for (int i = 0; i < n_row; i++) {
      for (int k = 0; k < n_col; k++) {
        for (int j = 0; j < r.n_col; j++) {
          res[i][j] += this->get(i, k) * r.get(k, j);
        }
      }
    }
    return res;
  }

  matrix operator^(long long n) const {
    assert(n_row == n_col);
    matrix res = identity(n_row);
    if (n == 0) return res;
    bool res_is_id = true;
    for (int i = 63 - __builtin_clzll(n); i >= 0; i--) {
      if (!res_is_id) res *= res;
      if ((n >> i) & 1) res *= (*this), res_is_id = false;
    }
    return res;
  }
};
#line 1 "algo/number-theory/modint.hpp"
using ll = long long;
template <const ll m>
struct Mod {
  ll v;

  Mod() : v(0){};
  Mod(ll _v) : v((_v + m) % m){};
  explicit operator ll() { return v; }
  Mod inv() const {
    ll a = v, b = m, ax = 1, bx = 0;
    while (b) {
      ll q = a / b, t = a % b;
      a = b, b = t, t = ax - bx * q, ax = bx, bx = t;
    }
    assert(a == 1);
    ax = (ax < 0 ? ax + m : ax);
    return ax;
  }
  Mod& operator+=(const Mod& that) {
    v = (v + that.v >= m ? v + that.v - m : v + that.v);
    return *this;
  }
  Mod& operator-=(const Mod& that) {
    v = (v >= that.v ? v - that.v : v + m - that.v);
    return *this;
  }
  Mod& operator*=(const Mod& that) {
    v = v * that.v % m;
    return *this;
  }
  Mod& operator/=(const Mod& that) { return (*this) *= that.inv(); }
  Mod operator^(ll y) {
    if (!y) return Mod(1);
    Mod r = *this ^ (y >> 1);
    r = r * r;
    return y & 1 ? *this * r : r;
  }
  Mod operator+(const Mod& that) const { return Mod(*this) += that; }
  Mod operator-(const Mod& that) const { return Mod(*this) -= that; }
  Mod operator*(const Mod& that) const { return Mod(*this) *= that; }
  Mod operator/(const Mod& that) const { return Mod(*this) /= that; }
  friend istream& operator>>(istream& in, Mod& that) {
    ll val;
    in >> val;
    that = Mod(val);
    return in;
  }
  friend ostream& operator<<(ostream& out, const Mod& that) {
    return out << that.v;
  }
};
#line 9 "Fibonacci_Numbers.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  using mint = Mod<1000000007>;
  long long n;
  cin >> n;
  matrix<mint> f({{1, 1}, {1, 0}});
  if (n == 0)
    cout << 0;
  else
    cout << (f ^ (n - 1))[0][0];
}
