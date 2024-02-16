#line 1 "E_-_Warp.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 2 "algo/number-theory/modint.hpp"

using ll = long long;

template <const ll m>
struct Mod {
  ll v;

  Mod() : v(0){};
  Mod(ll v) : v((v + m) % m){};
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
  bool operator==(const Mod& that) const { return this->v == that.v; }
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
#line 9 "E_-_Warp.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  set<pair<ll, ll>> obs;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    obs.insert({u, v});
  }

  using Fp = Mod<998244353>;
  map<pair<ll, ll>, Fp> dp;
  dp[{0, 0}] = 1;
  for (int i = 0; i < n; ++i) {
    map<pair<ll, ll>, Fp> ndp;
    for (auto [p, v] : dp) {
      auto [x, y] = p;
      if (!obs.count({x + a, y + b})) ndp[{x + a, y + b}] += v;
      if (!obs.count({x + c, y + d})) ndp[{x + c, y + d}] += v;
      if (!obs.count({x + e, y + f})) ndp[{x + e, y + f}] += v;
    }
    dp = move(ndp);
  }
  Fp ans = 0;
  for (auto [p, v] : dp) ans += v;
  cout << ans;
}
