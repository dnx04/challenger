#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

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

 private:
  int n;
  vector<int> p;
};

const int N = 1e5 + 1;
int p[N];

struct Edge {
  int a, b, w;
};

vector<Edge> g;

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> p[i], --p[i];

  bool lmao = true;
  for (int i = 0; i < n; ++i) lmao &= (p[i] == i);
  if (lmao) {
    cout << -1;
    return 0;
  }

  for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    g.push_back({--a, --b, w});
  }
  int lo = 1, hi = 1e9, ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    uf dsu(n);
    for (auto &e : g) {
      if (e.w >= mid) dsu.merge(e.a, e.b);
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) ok &= dsu.same(i, p[i]);
    if (ok)
      ans = mid, lo = mid + 1;
    else
      hi = mid - 1;
  }
  cout << ans;
}