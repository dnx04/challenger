#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  long long ans = 1e18;
  for (int i = 0; i < (1 << n); ++i) {
    vector<long long> sum(2);
    for (int j = 0; j < n; ++j) sum[(i >> j) & 1] += a[j];
    ans = min(ans, llabs(sum[0] - sum[1]));
  }
  cout << ans;
}