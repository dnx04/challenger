#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
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
  freopen("mootube.in", "r", stdin);
  freopen("mootube.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  struct Edge {
    int a, b, w;
    // compare edge by weight
    bool operator<(const Edge& e) const { return w < e.w; }
  };
  struct Query {
    int k, v, idx;
    // compare queries by k
    bool operator<(const Query& q) const { return k < q.k; }
  };
  vector<Edge> edges;
  vector<Query> query;
  for (int i = 0; i < n - 1; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    edges.push_back({--a, --b, w});
  }
  sort(rbegin(edges), rend(edges));
  for (int i = 0; i < q; ++i) {
    int k, v;
    cin >> k >> v;
    query.push_back({k, --v, i});
  }
  sort(rbegin(query), rend(query));
  uf dsu(n);
  vector<int> ans(q);
  for (int i = 0, j = 0; i < q; ++i) {
    auto [k, v, idx] = query[i];
    while (j < (int)edges.size() && edges[j].w >= k) {
      dsu.merge(edges[j].a, edges[j].b);
      ++j;
    }
    ans[idx] = dsu.size(v);
  }
  for (int i = 0; i < q; ++i) cout << ans[i] - 1 << '\n';
}