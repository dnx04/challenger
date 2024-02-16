#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  freopen("feast.in", "r", stdin);
  freopen("feast.out", "w", stdout);
  int t, a, b;
  cin >> t >> a >> b;
  vector<vector<bool>> vis(t + 1, vector<bool>(2));
  queue<pair<int, int>> q;
  q.push({0, 0});
  vis[0][0] = true;
  int ans = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    ans = max(ans, x);
    if (x + a <= t && !vis[x + a][y]) {
      vis[x + a][y] = true;
      q.push({x + a, y});
    }
    if (x + b <= t && !vis[x + b][y]) {
      vis[x + b][y] = true;
      q.push({x + b, y});
    }
    if (!y) {
      if (x / 2 <= t && !vis[x / 2][1]) {
        vis[x / 2][1] = true;
        q.push({x / 2, 1});
      }
    }
  }
  cout << ans;
}