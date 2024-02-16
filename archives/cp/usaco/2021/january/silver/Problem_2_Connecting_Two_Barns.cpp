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
    vector<int> c(n);
    int gn = g.size();
    for (int i = 0; i < gn; ++i) {
      for (auto ele : g[i]) {
        c[ele] = i;
      }
    }

    int ans = 1e18;

    vector<int> p1(n, 1e9), p2(n, 1e9);

    // 2 pointers to keep track of the closest pair of points we want to build a
    // path, lwb <-> proxy <-> upb, so we just need to keep track of the
    // greatest one smaller than proxy. Also lower_bound is gay, and handling edge case
    // of lower_bound is pain-in-the-ass.
    for (int i = 0, idx1 = 0, idx2 = 0; i <
    n; i++) {
      while (idx1 < (int)g[c[0]].size()) {
        p1[c[i]] = min(p1[c[i]], abs(i - g[c[0]][idx1]));
        if (g[c[0]][idx1] < i)
          idx1++;
        else
          break;
      }
      if (idx1) --idx1;
      while (idx2 < (int)g[c[n - 1]].size()) {
        p2[c[i]] = min(p2[c[i]], abs(i - g[c[n - 1]][idx2]));
        if (g[c[n - 1]][idx2] < i)
          idx2++;
        else
          break;
      }
      if (idx2) --idx2;
    }
    for (int i = 0; i < n; i++) ans = min(ans, p1[i] * p1[i] + p2[i] *
    p2[i]); cout << ans << "\n";
  }
}