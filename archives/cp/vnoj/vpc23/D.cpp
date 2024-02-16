#line 1 "D.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 1 "algo/data-structure/dsu.hpp"
struct dsu {
 public:
  dsu(int n) : n(n), p(n, -1) {}

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
#line 9 "D.cpp"

template <typename T>
T mst(int n, vector<tuple<T, int, int>>& edges) {
  sort(begin(edges), end(edges));
  dsu d(n);
  T ans = 0;
  for (auto [w, u, v] : edges) {
    if (d.same(u, v)) continue;
    ans += w, d.merge(u, v);
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<tuple<long double, int, int>> edges;
  vector<pair<ll, ll>> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
  long double w, c;
  cin >> w >> c;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ll dx = p[i].first - p[j].first, dy = p[i].second - p[j].second;
      long double dist = c * sqrt((long double)(dx * dx + dy * dy));
      edges.push_back({dist, i, j});
    }
  }

  auto ans = mst(n, edges);
  for(int i = 0; i < n; ++i) edges.push_back({w, i, n});
  ans = min(ans, mst(n + 1, edges));
  cout << fixed << setprecision(9) << ans;
}
