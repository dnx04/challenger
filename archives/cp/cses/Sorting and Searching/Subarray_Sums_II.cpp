#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n + 1);
  map<long long, int> cnt;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  partial_sum(begin(a), end(a), begin(a));
  long long ans = 0;
  for (int i = 0; i <= n; ++i) ans += cnt[a[i] - k], ++cnt[a[i]];
  cout << ans;
}