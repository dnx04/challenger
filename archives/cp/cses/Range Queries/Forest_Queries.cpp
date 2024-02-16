#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char ch;
      cin >> ch;
      a[i][j] = (ch == '*' ? 1 : 0);
    }
  }

  // matrix should be 1-indexed
  auto init = [&](vector<vector<int>> &a, int r, int c) {
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
      }
    }
  };
  auto sum = [&](const vector<vector<int>> &a, int r1, int c1, int r2, int c2) {
    return a[r2][c2] - a[r1 - 1][c2] - a[r2][c1 - 1] + a[r1 - 1][c1 - 1];
  };
  init(a, n, n);
  while (q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << sum(a, r1, c1, r2, c2) << '\n';
  }
}