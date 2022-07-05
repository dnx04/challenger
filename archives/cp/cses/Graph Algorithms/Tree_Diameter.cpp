#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define _GLIBCXX_ASSERTIONS
#endif

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

const int N = 2e5 + 1;
vector<int> g[N];
int n, max_depth = 0, pick = 1;

void dfs(int p, int u, int d = 0) {
  if (d > max_depth) pick = u, max_depth = d;
  for (auto v : g[u]) {
    if (p != v) dfs(u, v, d + 1);
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(1, 1);
  max_depth = 0;
  dfs(pick, pick);
  cout << max_depth;
}