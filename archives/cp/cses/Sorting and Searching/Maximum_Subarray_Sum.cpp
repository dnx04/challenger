#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  int64_t ans, sum = 0, mn = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (!i) ans = x;  // subarray must not be empty at first
    sum += x;
    ans = max(ans, sum - mn);
    mn = min(mn, sum);
  }
  cout << ans;
}