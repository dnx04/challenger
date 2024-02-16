#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<ll, int>>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(w, v);
  }
  vector<vector<ll>> d(2, vector<ll>(n, 1e18));
  using info = tuple<ll, int, int>;
  priority_queue<info, vector<info>, greater<info>> pq;
  d[0][0] = 0;
  pq.emplace(0, 0, 0);
  while (!pq.empty()) {
    auto [w, u, t] = pq.top();
    pq.pop();
    if (d[t][u] != w) continue;
    for (auto [w2, v] : g[u]) {
      if (d[t][v] > w + w2) {
        d[t][v] = w + w2;
        pq.emplace(d[t][v], v, t);
      }
      if (t == 0 && d[1][v] > w + w2 / 2) {
        d[1][v] = w + w2 / 2;
        pq.emplace(d[1][v], v, 1);
      }
    }
  }
  cout << d[1][n - 1];
}