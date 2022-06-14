#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

const int N = 1e6, INF = 1e9;
vector<int> dp(N + 1, INF);

int rec(int n) {
  int &res = dp[n], tmp = n;
  if (res != INF) return res;
  while (tmp) {
    if (tmp % 10 != 0) res = min(res, rec(n - (tmp % 10)) + 1);
    tmp /= 10;
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  dp[0] = 0;
  cout << rec(n);
}