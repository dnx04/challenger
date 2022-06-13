#include <bits/extc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  const long long MAX = 1e9;

  int n, t;
  cin >> n >> t;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  long long lo = 0, hi = 1e18, ans = 0;
  while (lo <= hi) {
    long long mid = (lo + hi) >> 1, product = 0;
    for (auto t : a) product = min(product + mid / t, MAX);
    if (product >= t)
      ans = mid, hi = mid - 1;
    else
      lo = mid + 1;
  }
  cout << ans;
}