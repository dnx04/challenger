#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  int ans = 0, cnt2 = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (i == 0 || i == n - 1)
      ans ^= x;
    else {
      int tmp1 = n - i, tmp2 = i;
      while (tmp1 % 2 == 0) tmp1 >>= 1, ++cnt2;
      while (tmp2 % 2 == 0) tmp2 >>= 1, --cnt2;
      if (!cnt2) ans ^= x;
    }
  }
  cout << ans;
}