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
vector<int> g[N], cnt(N, 1);
int n;

void dfs(int u) {
  for (auto v : g[u]) dfs(v), cnt[u] += cnt[v];
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int boss;
    cin >> boss;
    g[boss].push_back(i);
  }
  dfs(1);
  for(int i = 1; i <= n; ++i) cout << cnt[i] - 1 << ' ';
}