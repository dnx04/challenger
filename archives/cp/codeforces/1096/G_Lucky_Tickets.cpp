#line 1 "G_Lucky_Tickets.cpp"
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
#line 2 "algo/convolution/ntt.hpp"

// NTT modulo 998244353. If change modulo, change these parameters accordingly
using mint = Mod<998244353>;
mint G = 3;

void ntt(vector<mint>& a, bool invert) {
  int n = int(a.size()), s = 0;
  while ((1 << s) < n) s++;
  assert(1 << s == n);

  static vector<mint> ep, iep;
  while (int(ep.size()) <= s) {
    ep.push_back(G ^ ll(mint(-1) / (1 << ep.size())));
    iep.push_back(ep.back().inv());
  }
  vector<mint> b(n);
  for (int i = 1; i <= s; i++) {
    int w = 1 << (s - i);
    mint base = invert ? iep[i] : ep[i], now = 1;
    for (int y = 0; y < n / 2; y += w) {
      for (int x = 0; x < w; x++) {
        auto l = a[y << 1 | x];
        auto r = now * a[y << 1 | x | w];
        b[y | x] = l + r;
        b[y | x | n >> 1] = l - r;
      }
      now *= base;
    }
    swap(a, b);
  }
  if(invert) for(auto &x: a) x /= n;
}

vector<mint> nttconv(vector<mint> const& a, vector<mint> const& b) {
  vector<mint> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < int(a.size() + b.size())) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  ntt(fa, false);
  ntt(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  ntt(fa, true);
  fa.resize(int(a.size() + b.size() - 1));
  return fa;
}
#line 9 "G_Lucky_Tickets.cpp"

void solve([[maybe_unused]] int ith) {
  int n, k;
  cin >> n >> k;
  vector<mint> dp(10);
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    dp[x] = 1;
  }
  vector<mint> res({1});
  k = n / 2;
  while (k) {
    if (k & 1) res = nttconv(res, dp);
    dp = nttconv(dp, dp), k >>= 1;
  }
  mint ans = 0;
  for (auto v : res) ans += v * v;
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}
