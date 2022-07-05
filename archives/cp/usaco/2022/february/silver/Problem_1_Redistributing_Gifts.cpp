#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

const int N = 501;
vector<int> g[N];
bitset<N> able[N];

void dfs(int now, int to) {
  if (able[now][to]) return;
  able[now][to] = true;
  for (int nxt : g[to]) dfs(now, nxt);
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    g[i].resize(n);
    for (auto &x : g[i]) cin >> x;
    while (g[i].back() != i) g[i].pop_back();
  }
  for (int i = 1; i <= n; ++i) dfs(i, i);
  for (int i = 1; i <= n; ++i) {
    for (auto x : g[i]) {
      if (able[x][i]) {
        cout << x << '\n';
        break;
      }
    }
  }
}