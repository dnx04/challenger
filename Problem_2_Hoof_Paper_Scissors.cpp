#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  vector<char> ch(n + 1);
  for (int i = 1; i <= n; ++i) cin >> ch[i];
  int dp[n + 1][m + 1][3];
  memset(dp, 0, sizeof(dp));

  auto is_win = [](int a, char c) {
    if (a == 0 && c == 'P')
      return true;
    else if (a == 1 && c == 'S')
      return true;
    else if (a == 2 && c == 'H')
      return true;
    else
      return false;
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      for (int k = 0; k < 3; ++k) {  // [0, 1, 2] = [H, P, S] wins [P, S, H]
        dp[i + 1][j][k] =
            max(dp[i + 1][j][k], dp[i][j][k] + is_win(k, ch[i + 1]));
        if (j + 1 <= m) {
          for (int l = 0; l < 3; ++l) {
            if (l != k) {
              dp[i + 1][j + 1][l] =
                  max(dp[i + 1][j + 1][l], dp[i][j][k] + is_win(l, ch[i + 1]));
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; ++i)
    for (int j = 0; j < 3; ++j) ans = max(ans, dp[n][i][j]);
  cout << ans;
}