#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;

  const int N = 201;
  vector<vector<int>> a(N, vector<int>(N));
  for (int i = 0; i < n; ++i) {
    int xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    ++a[xa][ya];
    --a[xa][yb + 1];
    --a[xb + 1][ya];
    ++a[xb + 1][yb + 1];
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < N; ++j) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }
}