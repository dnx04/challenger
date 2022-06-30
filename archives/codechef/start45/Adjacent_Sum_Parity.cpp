#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int now = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (i < n - 1)
        now ^= x;
      else
        ok &= (now == x);
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}