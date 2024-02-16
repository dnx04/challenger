#line 1 "F_-_Transportation.cpp"
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
#line 9 "F_-_Transportation.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<ll> x(n), y(n), a(m), b(m), z(m);
  for(auto &i : x) cin >> i;
  for(auto &i : y) cin >> i;
  for(int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i] >> z[i];
    --a[i], --b[i];
  }

  const ll INF = 1e18;
  auto mst = [&](vector<pair<ll, pair<int, int>>> &edges) {
    sort(edges.begin(), edges.end());
    dsu d(n + 2);
    ll ans = 0;
    for(auto [w, e] : edges) {
      if(!d.same(e.first, e.second)) {
        d.merge(e.first, e.second);
        ans += w;
      }
    }
    if(d.size(0) < n) return INF;
    return ans;
  };
  vector<pair<ll, pair<int, int>>> edges;
  ll ans = INF;
  for(int c = 0; c < 4; ++c){
    edges.clear();
    if(c & 1) for(int i = 0; i < n; ++i) edges.push_back({x[i], {i, n}});
    if(c & 2) for(int i = 0; i < n; ++i) edges.push_back({y[i], {i, n + 1}});
    for(int i = 0; i < m; ++i) edges.push_back({z[i], {a[i], b[i]}});
    ans = min(ans, mst(edges));
  }
  cout << ans;
}
