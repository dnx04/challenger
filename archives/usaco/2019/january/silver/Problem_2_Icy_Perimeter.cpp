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

int n;
string b[N];
bool vis[N][N];
const int dr[]{1, -1, 0, 0}, dc[]{0, 0, 1, -1};

int max_area = 0, min_perimeter = 1e9;

bool in(int r, int c) { return (0 <= r && r < n && 0 <= c && c < n); }

void flood_fill(int sr, int sc) {
  int area = 0, perimeter = 0;
  queue<pair<int, int>> q;
  q.push({sr, sc});
  while (!q.empty()) {
    int r, c;
    tie(r, c) = q.front();
    q.pop();
    vis[r][c] = true;
    int add_perimeter = 4;
    for (int i = 0; i < 4; ++i) {
      int nr = r + dr[i], nc = c + dc[i];
      if (in(nr, nc) && b[nr][nc] == '#') {
        --add_perimeter;
        if (!vis[nr][nc]) {
          q.push({nr, nc});
          vis[nr][nc] = true;
        }
      }
    }
    ++area, perimeter += add_perimeter;
  }
  if (area >= max_area) {
    if (area > max_area)
      max_area = area, min_perimeter = perimeter;
    else
      min_perimeter = min(min_perimeter, perimeter);
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> b[i];

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (!vis[i][j] && b[i][j] == '#') flood_fill(i, j);
    }
  }
  cout << max_area << ' ' << min_perimeter;
}