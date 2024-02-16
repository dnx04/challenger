#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

const int N = 501, INF = 1e9;
vector<vector<int>> dp(N, vector<int>(N, INF));

int rec(int a, int b) {
  int &res = dp[a][b];
  if (res != INF) return res;
  if (a == b) return res = 0;
  for (int i = 1; i <= a - i; ++i)
    res = min(res, rec(i, b) + rec(a - i, b) + 1);
  for (int i = 1; i <= b - i; ++i)
    res = min(res, rec(a, i) + rec(a, b - i) + 1);
  return res;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int a, b;
  cin >> a >> b;
  cout << rec(a, b);
}