#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

const int N = 5001, INF = 1e9;
vector<vector<int>> dp(N, vector<int>(N, INF));
string sa, sb;

int rec(int a, int b) {
  int &res = dp[a][b];
  if (res != INF) return res;
  if (a == 0) return res = b;
  if (b == 0) return res = a;
  return res = min({rec(a, b - 1) + 1, rec(a - 1, b) + 1,
                    rec(a - 1, b - 1) + (sa[a - 1] != sb[b - 1])});
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> sa >> sb;
  cout << rec(sa.length(), sb.length());
}