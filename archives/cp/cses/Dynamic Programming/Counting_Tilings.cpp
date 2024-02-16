#line 1 "Counting_Tilings.cpp"
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
#line 9 "Counting_Tilings.cpp"

void solve([[maybe_unused]] int ith) {
  using Fp = Mod<1000000007>;
  int n, m;
  cin >> n >> m;
  vector<Fp> dp(1 << n);
  dp[(1 << n) - 1] = 1;
  for (int j = 0; j <= m; ++j) {
    for (int i = 0; i < n; ++i) {
      vector<Fp> ndp(1 << n);
      for (int k = 0; k < (1 << n); ++k) {
        ndp[k] += dp[k ^ (1 << i)];
        if (i && (k >> i & 1) && (k >> (i - 1) & 1)) {
          ndp[k] += dp[k ^ (1 << (i - 1))];
        }
      }
      dp = move(ndp);
    }
  }
  cout << dp[0];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}