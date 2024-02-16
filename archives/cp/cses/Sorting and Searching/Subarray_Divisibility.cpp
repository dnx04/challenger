#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1), cnt(n);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  partial_sum(begin(a), end(a), begin(a),
              [&](int x, int y) { return (((x + y) % n + n) % n); });

  long long ans = 0;
  for (int i = 0; i <= n; ++i) ans += cnt[a[i]], ++cnt[a[i]];
  cout << ans;
}