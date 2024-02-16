#line 1 "Counting_Bishops.cpp"
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
#line 9 "Counting_Bishops.cpp"

using Fp = Mod<1000000007>;

int squares(int i) {
  if (i & 1)
    return i / 4 * 2 + 1;
  else
    return (i - 1) / 4 * 2 + 2;
}

Fp bishop_placements(int N, int K) {
  if (K > 2 * N - 1) return 0;

  vector<vector<Fp>> D(N * 2, vector<Fp>(K + 1));
  for (int i = 0; i < N * 2; ++i) D[i][0] = 1;
  D[1][1] = 1;
  for (int i = 2; i < N * 2; ++i)
    for (int j = 1; j <= K; ++j)
      D[i][j] = D[i - 2][j] + D[i - 2][j - 1] * (squares(i) - j + 1);

  Fp ans = 0;
  for (int i = 0; i <= K; ++i) ans += D[N * 2 - 1][i] * D[N * 2 - 2][K - i];
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, k;
  cin >> n >> k;
  cout << bishop_placements(n, k);
}
