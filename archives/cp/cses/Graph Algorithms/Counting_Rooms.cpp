#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define _GLIBCXX_ASSERTIONS
#endif

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

const int N = 1001;

int n, m;
string b[N];
bool vis[N][N];
const int dr[]{1, -1, 0, 0}, dc[]{0, 0, 1, -1};

bool in(int r, int c) { return (0 <= r && r < n && 0 <= c && c < m); }

void flood_fill(int r, int c) {
  queue<pair<int, int>> q;
  q.push({r, c});
  while (!q.empty()) {
    int nr, nc;
    tie(nr, nc) = q.front();
    q.pop();
    if (!in(nr, nc) || vis[nr][nc] || b[nr][nc] == '#') continue;
    vis[nr][nc] = true;
    for (int i = 0; i < 4; ++i) q.push({nr + dr[i], nc + dc[i]});
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> b[i];

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!vis[i][j] && b[i][j] == '.') flood_fill(i, j), ++ans;
    }
  }
  cout << ans;
}