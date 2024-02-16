#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int64_t> sum(n + 1);
  for (int i = 1; i <= n; ++i) cin >> sum[i];
  sort(begin(sum), end(sum));
  partial_sum(begin(sum), end(sum), begin(sum));
  for (int i = 1; i <= n; ++i) {
    if (2 * sum[i - 1] + 1 < sum[i]) return cout << sum[i - 1] + 1, 0;
  }
  cout << sum[n] + 1;
}