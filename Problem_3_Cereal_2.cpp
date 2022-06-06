#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

const int N = 1e5 + 1;
int n, m;
vector<pair<int, int>> g[N];
bitset<N> chk;

int ans = 0;
vector<int> p_ans;

void dfs(int u) {
  chk[u] = true;
  for (auto e : g[u]) {
    if (!chk[e.first]) {
      p_ans.push_back(e.second);
      dfs(e.first);
    }
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back({v, i});
  }
  for (int i = 1; i <= n; ++i) {
    if (!chk[i]) dfs(i);
  }
  
  cout << g;
}