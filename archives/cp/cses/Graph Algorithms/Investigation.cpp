#line 1 "Investigation.cpp"
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
#line 9 "Investigation.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
  }
  using Fp = Mod<1000000007>;
  vector<ll> dist(n, 1e18);
  vector<Fp> cnt(n);
  vector<int> mn(n, 1e9), mx(n);
  using info = pair<ll, int>;
  priority_queue<info, vector<info>, greater<info>> pq;
  dist[0] = 0;
  cnt[0] = 1;
  mn[0] = mx[0] = 0;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d != dist[u]) continue;
    for (auto [v, w] : g[u]) {
      if (dist[v] > d + w) {
        dist[v] = d + w;
        cnt[v] = cnt[u];
        mn[v] = mn[u] + 1;
        mx[v] = mx[u] + 1;
        pq.emplace(dist[v], v);
      } else if (dist[v] == d + w) {
        cnt[v] += cnt[u];
        mn[v] = min(mn[v], mn[u] + 1);
        mx[v] = max(mx[v], mx[u] + 1);
      }
    }
  }
  cout << dist[n - 1] << ' ' << cnt[n - 1] << ' ' << mn[n - 1] << ' ' << mx[n - 1];
}
