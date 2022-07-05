#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

// works for mod < 2^63

using ull = unsigned long long;
template <ull m>
struct Mod {
  ull v;

  Mod() : v(0){};
  Mod(__uint128_t _v) : v(_v % m){};
  explicit operator ull() { return v; }
  Mod inv() const {
    int64_t a = v, b = m, ax = 1, bx = 0;
    while (b) {
      ull q = a / b, t = a % b;
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
    long double x;
    uint64_t c;
    int64_t r;
    x = v;
    c = x * that.v / m;
    r = (int64_t)(v * that.v - c * m) % (int64_t)m;
    v = (r < 0 ? r + m : r);
    return *this;
  }
  Mod& operator/=(const Mod& that) { return (*this) *= that.inv(); }
  Mod operator^(ull y) {
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
    ull val;
    in >> val;
    that = Mod(val);
    return in;
  }
  friend ostream& operator<<(ostream& out, const Mod& that) {
    return out << that.v;
  }
};

struct uf {
 public:
  uf(int _n) : n(_n), p(_n, -1) {}

  int merge(int a, int b) {
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    int x = head(a), y = head(b);
    if (x == y) return x;
    if (-p[x] < -p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    return head(a) == head(b);
  }

  int head(int a) {
    assert(0 <= a && a < n);
    if (p[a] < 0) return a;
    return p[a] = head(p[a]);
  }

  int size(int a) {
    assert(0 <= a && a < n);
    return -p[head(a)];
  }

  vector<vector<int>> groups() {
    vector<int> tmp(n), sz(n);
    for (int i = 0; i < n; ++i) tmp[i] = head(i), ++sz[tmp[i]];
    vector<vector<int>> gr(n);
    for (int i = 0; i < n; ++i) gr[i].reserve(sz[i]);
    for (int i = 0; i < n; ++i) gr[tmp[i]].push_back(i);
    gr.erase(remove_if(begin(gr), end(gr),
                       [&](const vector<int>& v) { return v.empty(); }),
             end(gr));
    return gr;
  }

 private:
  int n;
  vector<int> p;
};

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  using mint = Mod<998244353>;

  int n;
  cin >> n;
  vector<mint> g(n + 1);
  g[1] = 1, g[2] = 3;
  for (int i = 3; i <= n; ++i) g[i] = g[i - 1] + g[i - 2];

  uf dsu(n);
  vector<int> p(n), q(n);
  for (auto& x : p) cin >> x, --x;
  for (auto& x : q) cin >> x, --x;
  for (int i = 0; i < n; ++i) dsu.merge(p[i], q[i]);

  mint ans = 1;
  for(int i = 0; i < n; ++i){
    if(i == dsu.head(i)){
      ans *= g[dsu.size(i)];
    }
  }
  cout << ans;
}