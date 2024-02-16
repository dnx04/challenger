#line 1 "New_Roads_Queries.cpp"
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
                       [&](const vector<int> &v) { return v.empty(); }),
             end(gr));
    return gr;
  }

 private:
  int n;
  vector<int> p;
};
#line 9 "New_Roads_Queries.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<int, int>> edges(m), queries(q), seg(q, {0, m});
  vector<int> ans(q, -1);
  for (auto &[u, v] : edges) {
    cin >> u >> v;
    --u, --v;
  }
  for (auto &[u, v] : queries) {
    cin >> u >> v;
    --u, --v;
  }
  while (true) {
    dsu uf(n);
    vector<pair<int, int>> info;
    for (int i = 0; i < q; ++i) {
      auto [l, r] = seg[i];
      if (l > r) continue;
      info.push_back({(l + r) / 2, i});
    }
    if(info.empty()) break;
    sort(info.begin(), info.end());
    int ptr = 0;
    for (auto [mid, idx] : info) {
      while (ptr < mid) {
        uf.merge(edges[ptr].first, edges[ptr].second);
        ++ptr;
      }
      if (uf.same(queries[idx].first, queries[idx].second)) {
        ans[idx] = mid;
        seg[idx].second = mid - 1;
      } else {
        seg[idx].first = mid + 1;
      }
    }
  }
  for (auto x : ans) cout << x << '\n';
}