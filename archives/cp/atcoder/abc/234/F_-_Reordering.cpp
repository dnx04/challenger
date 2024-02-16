#line 1 "F_-_Reordering.cpp"
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
#line 9 "F_-_Reordering.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  string s;
  cin >> s;
  int n = s.size();
  using Fp = Mod<998244353>;
  vector<Fp> fac(n + 1, 1), ifac(n + 1, 1);
  vector<int> cnt(26);
  for (auto x : s) ++cnt[x - 'a'];
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i, ifac[i] = fac[i].inv();
  auto C = [&](int n, int m) { return fac[n] * ifac[m] * ifac[n - m]; };
  vector<Fp> dp(n + 1);
  dp[0] = 1;
  for (int i = 0; i < 26; ++i) {
    vector<Fp> ndp(n + 1);
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k <= min(j, cnt[i]); ++k) {
        ndp[j] += dp[j - k] * C(j, k);
      }
    }
    dp = move(ndp);
  }
  cout << accumulate(begin(dp), end(dp), Fp(0)) - 1;
}
