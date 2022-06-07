#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;

  sort(begin(p), end(p));
  for (int i = 0; i < n; ++i) p[i].first = i + 1;
  sort(begin(p), end(p), [&](const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
  });
  for (int i = 0; i < n; ++i) p[i].second = i + 1;

  vector<vector<int>> psum(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; ++i) psum[p[i].first][p[i].second] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
    }
  }
  auto sum = [&](int xa, int ya, int xb, int yb) {
    return psum[xb][yb] - psum[xa - 1][yb] - psum[xb][ya - 1] +
           psum[xa - 1][ya - 1];
  };

  int64_t ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      int64_t r1 = sum(1, i + 1, min(p[i].first, p[j].first), j + 1);
      int64_t r2 = sum(max(p[i].first, p[j].first), i + 1, n, j + 1);
      ans += r1 * r2;
    }
  }
  cout << ans + 1;
}