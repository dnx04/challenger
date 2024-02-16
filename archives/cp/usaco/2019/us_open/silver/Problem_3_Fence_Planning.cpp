#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

const int N = 1e5 + 1, mx = 1e9;
int x[N], y[N];
vector<int> g[N];
bitset<N> chk;

int xa = mx, ya = mx, xb = 0, yb = 0;

void dfs(int u) {
  xa = min(xa, x[u]);
  ya = min(ya, y[u]);
  xb = max(xb, x[u]);
  yb = max(yb, y[u]);
  chk[u] = true;
  for (auto v : g[u]) {
    if (!chk[v]) dfs(v);
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("fenceplan.in", "r", stdin);
  freopen("fenceplan.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  int ans = mx; 
  for(int i = 1; i <= n; ++i) {
    if(!chk[i]) {
      xa = mx, ya = mx, xb = 0, yb = 0;
      dfs(i);
      ans = min(ans, (xb - xa + yb - ya) * 2);
    }
  }
  cout << ans;
}