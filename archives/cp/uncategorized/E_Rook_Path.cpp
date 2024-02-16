#line 1 "E_Rook_Path.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 2 "algo/utility/static_modulo.hpp"

template <int mod>
struct static_modulo {
  using Fp = static_modulo;

 private:
  int x;

 public:
  static_modulo() : x(0) {}
  static_modulo(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
  Fp &operator+=(const Fp &p) {
    if ((x += p.x) >= mod) x -= mod;
    return *this;
  }
  Fp &operator-=(const Fp &p) {
    if ((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }
  Fp &operator*=(const Fp &p) {
    x = (int)(1ll * x * p.x % mod);
    return *this;
  }
  Fp &operator/=(const Fp &p) {
    *this *= p.inv();
    return *this;
  }
  Fp operator-() const { return Fp(-x); }
  Fp operator+(const Fp &p) const { return Fp(*this) += p; }
  Fp operator-(const Fp &p) const { return Fp(*this) -= p; }
  Fp operator*(const Fp &p) const { return Fp(*this) *= p; }
  Fp operator/(const Fp &p) const { return Fp(*this) /= p; }
  bool operator==(const Fp &p) const { return x == p.x; }
  bool operator!=(const Fp &p) const { return x != p.x; }
  Fp inv() const { return pow(mod - 2); }
  Fp pow(int64_t n) const {
    Fp ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const Fp &p) { return os << p.x; }
  friend istream &operator>>(istream &is, Fp &a) {
    int64_t t;
    is >> t;
    a = static_modulo<mod>(t);
    return (is);
  }
  int get() const { return x; }
  static constexpr int get_mod() { return mod; }
};
#line 9 "E_Rook_Path.cpp"

const int N = 1e6 + 1;

using Fp = static_modulo<998244353>;
Fp dp[N][2][2];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int h, w, k, x1, y1, x2, y2;
  cin >> h >> w >> k >> x1 >> y1 >> x2 >> y2;
  dp[0][x1 == x2][y1 == y2] = 1;
  for (int i = 0; i < k; ++i) {
    dp[i + 1][0][0] =
        dp[i][0][0] * (h + w - 4) + dp[i][0][1] * (w - 1) + dp[i][1][0] * (h - 1);
    dp[i + 1][0][1] = dp[i][0][1] * (h - 2) + dp[i][1][1] * (h - 1) + dp[i][0][0];
    dp[i + 1][1][0] = dp[i][1][0] * (w - 2) + dp[i][1][1] * (w - 1) + dp[i][0][0];
    dp[i + 1][1][1] = dp[i][0][1] + dp[i][1][0];
  }
  cout << dp[k][1][1];
}
