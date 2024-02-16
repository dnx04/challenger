#include <bits/extc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sort(begin(a), end(a));
  int l = 0, r = n - 1, ans = 0;
  while (l <= r) {
    ++ans;
    if (a[l] + a[r] <= k) ++l;
    --r;
  }
  cout << ans;
}