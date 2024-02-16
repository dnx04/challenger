#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  vector<ll> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back({max(h[v] - h[u], 0ll), v});
    g[v].push_back({max(h[u] - h[v], 0ll), u});
  }
  vector<ll> d(n, 1e18);
  d[0] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [dist, u] = pq.top();
    pq.pop();
    if (dist != d[u]) continue;
    for (auto [w, v] : g[u]) {
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        pq.push({d[v], v});
      }
    }
  }
  ll ans = -1e18;
  for(int i = 0; i < n; ++i) ans = max(ans, h[0] - h[i] - d[i]);
  cout << ans;
}