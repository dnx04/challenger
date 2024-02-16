#line 1 "E_Unfair_Sugoroku.cpp"
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
#line 9 "E_Unfair_Sugoroku.cpp"

using Fp = static_modulo<998244353>;

Fp dp[101][101][11];
bool vis[101][101][11];

int n, a, b, p, q;

Fp rec(int i, int j, int f) {
  if (vis[i][j][f]) return dp[i][j][f];
  Fp &res = dp[i][j][f];
  vis[i][j][f] = true;
  if (f == 0) {
    for (int k = 1; k <= p; ++k) res += rec(min(i + k, n), j, 1);
    res /= p;
  }
  if (f == 1) {
    for (int k = 1; k <= q; ++k) res += rec(i, min(j + k, n), 0);
    res /= q;
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  cin >> n >> a >> b >> p >> q;
  for (int i = 1; i <= n; ++i)
    dp[n][i][0] = dp[n][i][1] = 1, vis[n][i][0] = vis[n][i][1] = true;
  for (int i = 1; i <= n; ++i)
    dp[i][n][0] = dp[i][n][1] = 0, vis[i][n][0] = vis[i][n][1] = true;
  cout << rec(a, b, 0);
}
