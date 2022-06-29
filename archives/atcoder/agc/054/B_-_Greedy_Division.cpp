#include "bits/extc++.h"

using namespace std;

#ifdef LOCAL
#include "lib/prettyprint.hpp"
#endif

// works for mod < 2^63

using ull = unsigned long long;
template <const ull m>
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
    v = (__uint128_t)v * that.v % m;
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
  using mint = Mod<998244353>;
  const int N = 101;

  int n, sum = 0;
  cin >> n;
  vector<int> a(n);
  vector<mint> f(n + 1, 1);
  for (int i = 1; i <= n; ++i) f[i] = f[i - 1] * i;
  for (auto& v : a) cin >> v;
  sum = accumulate(begin(a), end(a), 0);
  if (sum & 1) {
    cout << 0;
    return 0;
  }
  sum /= 2;
  mint dp[N][N * N];
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j >= 0; --j) {
      for (int k = 0; k + a[i] <= sum; ++k) {
        dp[j + 1][k + a[i]] += dp[j][k];
      }
    }
  }
  mint ans = 0;
  for (int i = 1; i < n; ++i) ans += dp[i][sum] * f[i] * f[n - i];
  cout << ans;
}