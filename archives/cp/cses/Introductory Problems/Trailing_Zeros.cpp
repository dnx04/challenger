#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int64_t n;
  cin >> n;
  int ans = 0;
  for (int64_t i = 5; i <= n; i *= 5) ans += n / i;
  cout << ans;
}