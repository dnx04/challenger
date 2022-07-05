#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b, n;
    cin >> a >> b >> n;
    int targ = a ^ b, now = 0, res = 0, step = 0;
    for (int i = 29; i >= 0; --i) {
      if (((targ >> i) & 1)) {
        if ((step ^ (1 << i)) < n) {
          step ^= (1 << i);
        } else if (step) {
          now ^= step;
          step = (1 << i);
          ++res;
        }
      }
    }
    if (step) ++res, now ^= step;
    if (now != targ)
      cout << -1 << '\n';
    else
      cout << res << '\n';
  }
}