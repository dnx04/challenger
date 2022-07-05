#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
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
  using mint = Mod<(ll)1e9 + 7>;
  const int N = 5000;
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  sort(begin(a), end(a));
  vector<vector<mint>> dp(n / 2 + 1, vector<mint>(2 * N + 1));
  vector<vector<mint>> ndp(n / 2 + 1, vector<mint>(2 * N + 1));
  dp[0][N] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= n / 2; ++j) {
      for (int k = 0; k <= 2 * N; ++k) {
        ndp[j][k] += dp[j][k] * (j + 1);
        if (k >= a[i] && j + 1 <= n / 2)
          ndp[j][k] += dp[j + 1][k - a[i]] * (j + 1);
        if (j && k + a[i] <= 2 * N) ndp[j][k] += dp[j - 1][k + a[i]];
      }
    }
    swap(dp, ndp);
    fill(begin(ndp), end(ndp), vector<mint>(2 * N + 1));
  }
  mint ans = 0;
  for (int i = N; i <= N + x; ++i) ans += dp[0][i];
  cout << ans;
}