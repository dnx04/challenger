#line 1 "G_-_Yet_Another_RGB_Sequence.cpp"
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
#line 9 "G_-_Yet_Another_RGB_Sequence.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  using Fp = Mod<998244353>;
  const int N = 2e6 + 1;
  vector<Fp> fac(N, 1);
  for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i;
  auto C = [&](int n, int k) {
    if (k < 0 || k > n) return Fp(0);
    return fac[n] / fac[k] / fac[n - k];
  };

  int r, g, b, k;
  cin >> r >> g >> b >> k;
  int spots = b + k + 1;
  cout << fac[b + r] / fac[r - k] / fac[b] / fac[k] *
              C(g - k + spots - 1, g - k);
}
