#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int64_t ans = 1e18, a[3];
  cin >> a[0] >> a[1] >> a[2];
  for (int i = 0; i < 3; ++i) {
    if (a[i] % 2 == 0)
      ans = 0;
    else
      ans = min(ans, a[(i + 1) % 3] * a[(i + 2) % 3]);
  } 
  cout << ans;
}