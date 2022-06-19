#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> g[n];
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v, --u, --v;
    g[u].push_back(v), g[v].push_back(u);
  }
  int ans = n + 1;
  for (int i = 0; i < n; ++i) {
    vector<int> lv(n, -1);
    queue<pair<int, int>> q;
    q.push({i, i});
    lv[i] = 0;
    while (!q.empty()) {
      int p, u;
      tie(p, u) = q.front();
      q.pop();
      for (auto v : g[u]) {
        if (v != p) {
          if (lv[v] == -1) {
            lv[v] = lv[u] + 1;
            q.push({u, v});
          } else {
            ans = min(ans, lv[u] + lv[v] + 1);
          }
        }
      }
    }
  }
  if (ans == n + 1)
    cout << -1;
  else
    cout << ans;
}