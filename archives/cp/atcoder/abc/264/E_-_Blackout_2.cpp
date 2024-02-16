#line 1 "E_-_Blackout_2.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#line 1 "algo/data-structure/union_find.hpp"
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
#line 8 "E_-_Blackout_2.cpp"

void solve(int ith) {
  int n, m, e;
  cin >> n >> m >> e;
  vector<int> u(e), v(e);
  for (int i = 0; i < e; ++i) {
    cin >> u[i] >> v[i];
    --u[i], --v[i];
  }
  vector<int> electro(e, 1);
  int q;
  cin >> q;
  vector<int> query(q);
  for (auto &x : query) {
    cin >> x;
    --x;
    electro[x] = 0;
  }

  uf dsu(n + m);
  vector<int> w(n + m);
  for (int i = n; i < n + m; ++i) w[i] = 1;
  int cur = 0;
  for (int i = 0; i < e; ++i) {
    if (electro[i] == 0) continue;
    if (dsu.same(u[i], v[i])) continue;
    int wu = w[dsu.head(u[i])], wv = w[dsu.head(v[i])];
    if (wu == 0 && wv == 1) cur += dsu.size(u[i]);
    if (wu == 1 && wv == 0) cur += dsu.size(v[i]);
    dsu.merge(u[i], v[i]);
    w[dsu.head(u[i])] = max(wu, wv);
  }
  vector<int> res(q);
  for (int j = q - 1; j >= 0; --j) {
    int i = query[j];
    res[j] = cur;
    if (dsu.same(u[i], v[i])) continue;
    int wu = w[dsu.head(u[i])], wv = w[dsu.head(v[i])];
    if (wu == 0 && wv == 1) cur += dsu.size(u[i]);
    if (wu == 1 && wv == 0) cur += dsu.size(v[i]);
    dsu.merge(u[i], v[i]);
    w[dsu.head(u[i])] = max(wu, wv);
  }
  for (auto v : res) cout << v << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}
