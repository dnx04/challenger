#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

#define int long long

const int N = 201;

vector<int> g[N];
vector<bool> chk(N);
int ans = 0, cnt = 0;

void dfs(int u) {
  chk[u] = true;
  ++cnt;
  for (auto v : g[u]) {
    if (!chk[v]) dfs(v);
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
  int n;
  cin >> n;
  int x[n], y[n], r[n];
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i] >> r[i];
  }
  auto sqr = [&](int x) { return x * x; };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j && sqr(x[i] - x[j]) + sqr(y[i] - y[j]) <= r[i] * r[i]) {
        g[i].push_back(j);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    fill(begin(chk), end(chk), false);
    dfs(i);
    ans = max(ans, cnt);
    cnt = 0;
  }
  cout << ans;
}