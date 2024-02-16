#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  const int N = 1e5 + 1;
  bitset<N> dp;
  dp[0] = 1;  
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    dp |= (dp << x);
  }
  cout << dp.count() - 1 << '\n';
  for (int i = 1; i < N; ++i) {
    if (dp[i]) cout << i << ' ';
  }
}