#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int64_t> a(n);
  for (auto &x : a) cin >> x;
  sort(begin(a), end(a));
  int64_t ans = 0;
  for (int i = 0; i < n; ++i) ans += abs(a[i] - a[n / 2]);  // median
  cout << ans;
}