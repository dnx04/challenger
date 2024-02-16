#line 1 "E_Almost_Perfect.cpp"
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
#line 9 "E_Almost_Perfect.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  using Fp = Mod<998244353>;
  const int N = 6e5 + 1;

  vector<Fp> f(N), I(N);
  f[0] = 1;
  for (int i = 1; i < N; ++i) f[i] = f[i - 1] * i;
  I[0] = 1, I[1] = 1, I[2] = 2;
  for (int i = 3; i < N; ++i) I[i] = I[i - 1] + I[i - 2] * (i - 1);
  auto C = [&](int n, int m) { return f[n] / f[m] / f[n - m]; };

  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    Fp ans = 0;
    for (int i = 0; 4 * i <= n; ++i) {
      ans += C(n - 2 * i, 2 * i) * f[2 * i] / f[i] * I[n - 4 * i];
    }
    cout << ans << '\n';
  }
}
