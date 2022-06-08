#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

// UDLR
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

const int len = 48;

bitset<9> chk[9];  // 1-indexed for easier implementation
vector<int> d(len, -1);

int rec(int r, int c, int step) {
  // can't go forward but can go left right
  if ((!chk[r + 1][c] && !chk[r - 1][c]) && (chk[r][c - 1] && chk[r][c + 1]))
    return 0;
  if ((chk[r + 1][c] && chk[r - 1][c]) && (!chk[r][c - 1] && !chk[r][c + 1]))
    return 0;

  // arrived too early
  if (r == 7 && c == 1) {
    if (step == len)
      return 1;
    else
      return 0;
  }

  // main calculation
  int res = 0;
  chk[r][c] = true;
  if (d[step] != -1) {
    int nr = r + dr[d[step]], nc = c + dc[d[step]];
    if (!chk[nr][nc]) res += rec(nr, nc, step + 1);
  } else {
    for (int i = 0; i < 4; ++i) {
      if (!chk[r + dr[i]][c + dc[i]])
        res += rec(r + dr[i], c + dc[i], step + 1);
    }
  }
  chk[r][c] = false;
  return res;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  for (int i = 0; i < len; ++i) {
    char ch;
    cin >> ch;
    if (ch == 'U')
      d[i] = 0;
    else if (ch == 'D')
      d[i] = 1;
    else if (ch == 'L')
      d[i] = 2;
    else if (ch == 'R')
      d[i] = 3;
  }
  for (int i = 0; i <= 8; ++i) {  // bordering
    chk[0][i] = true;
    chk[8][i] = true;
    chk[i][0] = true;
    chk[i][8] = true;
  }
  cout << rec(1, 1, 0);
}