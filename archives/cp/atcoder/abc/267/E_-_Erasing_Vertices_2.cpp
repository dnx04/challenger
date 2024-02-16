#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  set<ll> s;
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<ll> cost(n + 1);
  for (int i = 1; i <= n; ++i) {
    for (auto v : g[i]) cost[i] += a[v];
  }
  set<pair<ll, int>> st;
  set<int> erased;
  for (int i = 1; i <= n; ++i) st.insert({cost[i], i});
  ll ans = 0;
  while (!st.empty()) {
    auto [c, u] = *begin(st);
    ans = max(ans, c);
    for (auto v : g[u]) {
      if (!erased.count(v)) {
        st.erase(st.find({cost[v], v}));
        cost[u] -= a[v];
        cost[v] -= a[u];
        if (cost[v] > 0) st.insert({cost[v], v});
      }
    }
    erased.insert(u);
    st.erase(st.find({c, u}));
    if (cost[u] > 0) st.insert({cost[u], u});
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}