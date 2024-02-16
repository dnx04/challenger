#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  vector<int> c(n);
  vector<map<int, int>> cnt(n);
  vector<int> dsu(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    dsu[i] = i;
    ++cnt[i][c[i]];
  }
  auto head = [&](auto head, int u) -> int {
    return dsu[u] == u ? u : head(head, dsu[u]);
  };
  auto merge = [&](int u, int v) {
    u = head(head, u);
    v = head(head, v);
    if (u == v) return;
    if (cnt[u].size() < cnt[v].size()) swap(u, v);
    for (auto [k, v] : cnt[v]) {
      cnt[u][k] += v;
    }
    cnt[v].clear();
    dsu[v] = u;
  };
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      merge(u, v);
    } else {
      int u, x;
      cin >> u >> x;
      --u;
      cout << cnt[head(head, u)][x] << '\n';
    }
  }
}