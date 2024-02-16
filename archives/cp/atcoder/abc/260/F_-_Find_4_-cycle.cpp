#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int s, t, m;
  cin >> s >> t >> m;
  vector<vector<int>> g(s);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u - 1].push_back(v - s - 1);
  }
  vector<vector<int>> adj(t, vector<int>(t, -1));
  for (int i = 0; i < s; ++i) {
    for (const auto &u : g[i]) {
      for (const auto &v : g[i]) {
        if (u != v && adj[u][v] != -1) {
          cout << i + 1 << ' ' << adj[u][v] + 1 << ' ' << u + s + 1 << ' '
               << v + s + 1 << '\n';
          return 0;
        }
        adj[u][v] = i;
      }
    }
  }
  cout << -1;
}