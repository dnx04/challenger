#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  vector<int> p(n + 1), c(n + 1), deg(n + 1);
  for (int i = 2; i <= n; ++i) cin >> p[i], ++deg[i], ++deg[p[i]];
  while (q--) {
    int m;
    ll ans = 0;
    cin >> m;
    bool is1 = false;
    vector<int> vertex;
    for (int i = 0; i < m; ++i) {
      int u;
      cin >> u;
      vertex.push_back(u);
      ans += deg[u];
      if (u == 1) is1 = true;
      c[u] = 1;
    }
    for (auto u : vertex) {
      if (c[u] == c[p[u]]) ans -= 2;
    }
    cout << ans + is1 << '\n';
    for (auto u : vertex) c[u] = 0;
  }
}