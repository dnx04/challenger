#line 1 "Road_Reparation.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 1 "algo/data-structure/dsu.hpp"
struct dsu {
 public:
  dsu(int _n) : n(_n), p(_n, -1) {}

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
#line 9 "Road_Reparation.cpp"

auto mst = [](const vector<vector<pair<int, int>>>& g) -> ll {
  using edge = tuple<ll, int, int>;
  int n = g.size();
  dsu uf(n);
  priority_queue<edge, vector<edge>, greater<edge>> pq;
  for (int i = 0; i < n; ++i) {
    for (auto [j, w] : g[i]) {
      pq.emplace(w, i, j);
    }
  }
  ll res = 0;
  while (!pq.empty()) {
    auto [w, i, j] = pq.top();
    pq.pop();
    if (!uf.same(i, j)) {
      res += w;
      uf.merge(i, j);
    }
  }
  if (uf.groups().size() >= 2) return -1;
  return res;
};

void solve([[maybe_unused]] int ith) {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
  }
  cout << (mst(g) == -1 ? "IMPOSSIBLE" : to_string(mst(g)));
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}
