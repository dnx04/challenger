#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "tools/prettyprint.hpp"
#endif

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

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  string s;
  cin >> s;
  using mint = Mod<ll(1e9) + 7>;
  int n = s.length();
  if (n & 1)
    cout << 0;
  else {
    vector<mint> f(n + 1, 1);
    for (int i = 1; i <= n; ++i) f[i] = f[i - 1] * i;
    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1));
    vector<vector<mint>> C(n / 2 + 1, vector<mint>(n / 2 + 1));
    C[0][0] = 1;
    for (int i = 1; i <= n / 2; ++i) {
      C[i][0] = 1;
      for (int j = 1; j <= i; ++j) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    for (int i = 0; i + 1 <= n; ++i) dp[i + 1][i] = 1;
    for (int i = n - 1; i >= 0; --i)
      for (int j = i + 1; j < n; j += 2) {
        for (int k = i + 1; k <= j; k += 2)
          if (s[i] == s[k]) {
            dp[i][j] += dp[i + 1][k - 1] * dp[k + 1][j] *
                        C[(j - i + 1) / 2][(k - i + 1) / 2];
          }
      }
    cout << dp[0][n - 1];
  }
}