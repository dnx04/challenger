#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define _GLIBCXX_ASSERTIONS
#endif

#include <bits/extc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

const int N = 2e5 + 1;

vector<int> nxt(N), len(N);
bitset<N> vis;
queue<int> path;
int step = 0;

void dfs(int u) {
  path.push(u);
  if (vis[u]) {
    step += len[u];
    return;
  }
  vis[u] = true;
  ++step;
  dfs(nxt[u]);
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> nxt[i];
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      step = 0;
      dfs(i);
      int dec = 1;
      while (!path.empty()) {
        if (path.front() == path.back()) dec = 0;
        len[path.front()] = step;
        step -= dec;
        path.pop();
      }
    }
  }
  for (int i = 1; i <= n; ++i) cout << len[i] << ' ';
}