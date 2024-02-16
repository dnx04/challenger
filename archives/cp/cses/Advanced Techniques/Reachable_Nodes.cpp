#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

const int N = 5e4 + 1;
bitset<N> ans[N];
vector<int> in(N), g[N];
queue<int> q;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    g[y].push_back(x);
    ++in[x];
  }
  for (int i = 1; i <= n; ++i) {
    if (!in[i]) ans[i].set(i), q.push(i);
  }
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto v : g[u]) {
      ans[v] |= ans[u];
      --in[v];
      if (!in[v]) ans[v].set(v), q.push(v);
    }
  }
  for(int i = 1; i <= n; ++i) cout << ans[i].count() << ' ';
}