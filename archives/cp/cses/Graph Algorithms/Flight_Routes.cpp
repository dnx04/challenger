#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<ll, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w);
  }
  using info = pair<ll, int>;
  vector<priority_queue<ll>> d(n);
  priority_queue<info, vector<info>, greater<info>> pq;
  d[0].push(0);
  pq.emplace(0, 0);
  while (!pq.empty()) {
    auto [dist, u] = pq.top();
    pq.pop();
    if (d[u].top() < dist) continue;
    for (auto [v, w] : g[u]) {
      if ((int)d[v].size() < k) {
        d[v].push(dist + w);
        pq.emplace(dist + w, v);
      } else if (d[v].top() > dist + w) {
        d[v].pop();
        d[v].push(dist + w);
        pq.emplace(dist + w, v);
      }
    }
  }
  vector<ll> ans;
  while (!d[n - 1].empty()) ans.push_back(d[n - 1].top()), d[n - 1].pop();
  reverse(ans.begin(), ans.end());
  for (auto x : ans) cout << x << ' ';
}