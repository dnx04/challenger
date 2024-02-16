#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

// works for mod < 2^63

using ull = unsigned long long;
template <ull m>
struct Mod {
  ull v;

  Mod() : v(0){};
  Mod(__uint128_t _v) : v(_v % m){};
  explicit operator ull() { return v; }
  Mod inv() const {
    int64_t a = v, b = m, ax = 1, bx = 0;
    while (b) {
      ull q = a / b, t = a % b;
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
    long double x;
    uint64_t c;
    int64_t r;
    x = v;
    c = x * that.v / m;
    r = (int64_t)(v * that.v - c * m) % (int64_t)m;
    v = (r < 0 ? r + m : r);
    return *this;
  }
  Mod& operator/=(const Mod& that) { return (*this) *= that.inv(); }
  Mod operator^(ull y) {
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
    ull val;
    in >> val;
    that = Mod(val);
    return in;
  }
  friend ostream& operator<<(ostream& out, const Mod& that) {
    return out << that.v;
  }
};

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  const int N = 1e6 + 1;
  using mint = Mod<ull(1e9 + 7)>;
  vector<mint> f(N, 1);
  for (int i = 2; i < N; ++i) f[i] = f[i - 1] * i;
  int n;
  cin >> n;

  while (n--) {
    int n, k;
    cin >> n >> k;
    cout << f[n] / f[k] / f[n - k] << '\n';
  }
}