#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(begin(a), end(a));
  cout << a << '\n';
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int itr = upper_bound(begin(a), end(a), a[i] + k) - begin(a);
    ans = max(ans, itr - i);
  }
  cout << ans;
}