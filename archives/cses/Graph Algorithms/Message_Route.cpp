#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> g[n + 1], p(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b), g[b].push_back(a);
  }
  queue<int> q;
  q.push(1);
  p[1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : g[u]) {
      if (!p[v]) {
        p[v] = u;
        q.push(v);
      }
    }
  }
  int ptr = n;
  vector<int> ans;
  while (true) {
    ans.push_back(ptr);
    if (ptr == p[ptr]) break;
    ptr = p[ptr];
  }
  reverse(begin(ans), end(ans));
  if (ans[0] != 1) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  cout << ans.size() << '\n';
  for (auto v : ans) cout << v << ' ';
}