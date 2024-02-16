#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<int> deg(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    ++deg[u], ++deg[v];
  }
  bool ok = true;
  for (int i = 1; i <= n; ++i) ok &= (deg[i] % 2 == 0);
  cout << (ok ? "YES" : "NO");
}