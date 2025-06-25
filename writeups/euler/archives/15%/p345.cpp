#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()

using ll = long long;
using ld = long double;
using ull = unsigned long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ifstream cin("input.txt");
  int d[15][15];
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      cin >> d[i][j];
    }
  }
  int dp[1 << 15][15];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < 15; i++) {
    dp[1 << i][i] = d[0][i];
  }
  for (int mask = 0; mask < (1 << 15); mask++) {
    for (int i = 0; i < 15; i++) {
      if (mask & (1 << i)) {
        for (int j = 0; j < 15; j++) {
          if (!(mask & (1 << j))) {
            dp[mask | (1 << j)][j] =
                max(dp[mask | (1 << j)][j], dp[mask][i] + d[__builtin_popcount(mask)][j]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < 15; i++) {
    ans = max(ans, dp[(1 << 15) - 1][i]);
  }
  cout << ans << '\n';
}