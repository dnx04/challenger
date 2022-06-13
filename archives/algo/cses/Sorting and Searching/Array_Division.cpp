#include <bits/extc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
  long long l = 0, r = 1e18, ans = 0;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    int cnt = 0, now = 0;
    while (now < n) {
      auto itr = upper_bound(begin(a) + now, end(a), a[now] + mid) - begin(a);
      --itr;
      if(now == itr) break;
      now = itr, ++cnt;
    }
    if (now == n && cnt <= k)
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans;
}