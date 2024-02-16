#include <bits/extc++.h>

using namespace std;

using ll = long long;

const int N = 2e5 + 5;
vector<int> deg(N), g[N];
set<int> cycle;
int cnt = 0;
map<int, int> comp;

void dfs(int p, int u) {
  comp[u] = cnt;
  for (auto v : g[u]) {
    if (!cycle.count(v) && v != p) dfs(u, v);
  }
}

void solve(int ith) {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    deg[u] += 1, deg[v] += 1;
    g[u].push_back(v), g[v].push_back(u);
    cycle.insert(i + 1);
  }
  for (int i = 1; i <= n; ++i) {
    int tmp = i;
    while (deg[tmp] == 1) {
      --deg[tmp];
      cycle.erase(tmp);
      for (auto v : g[tmp]) {
        if (deg[v]) {
          --deg[v];
          tmp = v;
          break;
        }
      }
    }
  }
  for (auto v : cycle) {
    ++cnt;
    dfs(v, v);
  }
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << (comp[u] == comp[v] ? "Yes\n" : "No\n");
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}