#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int64_t> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  partial_sum(begin(a), end(a), begin(a));
  int ans = 0;
  for (int i1 = 1, i2 = 0; i1 <= n; ++i1) {
    while (i2 < i1 && a[i1] - a[i2] > k) ++i2;
    if(a[i1] - a[i2] == k) ++ans;
  }
  cout << ans;
}