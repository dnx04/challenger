#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  long long ans = 0, prv = 0;
  for (int i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    ans += max(0ll, prv - x);
    prv = max(prv, x);
  }
  cout << ans;
}