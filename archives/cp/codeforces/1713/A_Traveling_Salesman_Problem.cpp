#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "tools/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  const int LIM = 100;
  int tc;
  cin >> tc;
  while (tc--) {
    int n, mxx = -LIM, mxy = -LIM, mnx = LIM, mny = LIM;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      mxx = max(mxx, x);
      mxy = max(mxy, y);
      mnx = min(mnx, x);
      mny = min(mny, y);
    }
    mnx = min(mnx, 0);
    mny = min(mny, 0);
    mxx = max(mxx, 0);
    mxy = max(mxy, 0);
    cout << 2 * (mxx - mnx + mxy - mny) << '\n';
  }
}