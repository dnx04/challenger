#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("cbarn2.in", "r", stdin);
  freopen("cbarn2.out", "w", stdout);
  const long long INF = 1e18;
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (auto &x : A) cin >> x;
  long long res = INF;
  vector<vector<long long>> dp(N + 1);
  for (int i = 0; i < N; ++i) {
    fill(begin(dp), end(dp), vector<long long>(N + 1, INF));
    dp[0][N] = 0;
    for (int k = 1; k <= K; ++k) {
      for (int j = 0; j < N; ++j) {
        // dp(k, j): k doors placed, the last door placed is at position j
        // dp is calculated from N -> 0
        long long val = 0;
        for (int a = j + 1; a <= N; ++a) {
          val += A[a - 1] * (a - j - 1);
          dp[k][j] = min(dp[k][j], val + dp[k - 1][a]);
        }
      }
    }
    res = min(res, dp[K][0]);
    rotate(begin(A), begin(A) + 1, end(A));
  }
  cout << res;
}