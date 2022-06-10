#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

vector<vector<int>> board(8, vector<int>(8));
int ans = 0;

void apply(int x, int y, int val) {
  for (int k = 0; k < 8; ++k) {
    if (board[x][k] != -1) board[x][k] += val;
    if (board[k][y] != -1) board[k][y] += val;
    if (k) {
      if (min(x, y) - k >= 0 && board[x - k][y - k] != -1)
        board[x - k][y - k] += val;
      if (max(x, y) + k < 8 && board[x + k][y + k] != -1)
        board[x + k][y + k] += val;
      if (x - k >= 0 && y + k < 8 && board[x - k][y + k] != -1)
        board[x - k][y + k] += val;
      if (y - k >= 0 && x + k < 8 && board[x + k][y - k] != -1)
        board[x + k][y - k] += val;
    }
  }
}

void rec(int row, int pc = 0) {
  if (row == 8) {
    if (pc == 8) ++ans;
    return;
  }
  for (int col = 0; col < 8; ++col) {
    if (!board[row][col]) {
      apply(row, col, 1);
      rec(row + 1, pc + 1);
      apply(row, col, -1);
    }
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      char ch;
      cin >> ch;
      if (ch == '*') board[i][j] = -1;
    }
  }
  rec(0);
  cout << ans;
}