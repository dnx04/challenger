#include "bits/extc++.h"

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#ifdef DEBUG
#include "tools/prettyprint.hpp"
#endif

const int N = 1e5 + 1;

struct Edge {
  int v, w;
};
vector<Edge> g[N];
vector<int> ans(N);

void dfs(int p, int u, int parity = 0) {
  ans[u] = parity;
  for (auto to : g[u]) {
    auto [v, w] = to;
    if (v != p) {
      dfs(u, v, parity ^ (w & 1));
    }
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].emplace_back(Edge{v, w});
    g[v].emplace_back(Edge{u, w});
  }
  dfs(1, 1);
  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}