// don't know where am I fucking up
// got rekt on test 9 and 10

#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

#define int long long

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
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    uf dsu(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      dsu.merge(--u, --v);
    }
    vector<vector<int>> g = dsu.groups();
    int gn = g.size(), gs = 0, gf = 0;
    vector<int> tail[gn];
    for (int i = 0; i < gn; ++i) {
      auto [mn, mx] = minmax_element(begin(g[i]), end(g[i]));
      tail[i] = vector<int>({*mn, *mx});
      for (auto ele : g[i]) {
        if (ele == 0) gs = i;
        if (ele == n - 1) gf = i;
      }
    }
    cout << gn << '\n';
    auto sqr = [&](int x) { return 1ll * x * x; };
    int ans = 1e18;

    // 1 edge brute forcing
    for (int k1 : {0, 1}) {
      for (int k2 : {0, 1}) {
        ans = min(ans, sqr(tail[gs][k1] - tail[gf][k2]));
      }
    }
    // 2 edges brute forcing
    for (int i = 0; i < gn; ++i) {
      for (int x : {0, 1}) {
        for (int k1 : {0, 1}) {
          for (int k2 : {0, 1}) {
            for (int y : {0, 1}) {
              int p1 = sqr(tail[gs][x] - tail[i][k1]);
              int p2 = sqr(tail[i][k2] - tail[gf][y]);
              ans = min(ans, p1 + p2);
            }
          }
        }
      }
    }
    cout << ans << '\n';
  }
}