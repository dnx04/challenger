#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = k + 1; i <= n; ++i) ans += (i - 2) / 5 != (i - 1) / 5;
    cout << ans << '\n';
  }
}