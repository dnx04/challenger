#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, a, b, x = 0;
    cin >> n >> a >> b;
    bool cross = false;
    for (int i = n - 1; i >= 0; --i) {
      int ba = (a >> i) & 1, bb = (b >> i) & 1;
      if (ba == bb)
        x ^= ((ba ^ 1) << i);
      else {
        if (!cross) {
          cross = true;
          x ^= ((ba ^ 1) << i);
        } else {
          x ^= ((bb ^ 1) << i);
        }
      }
    }
    cout << x << '\n';
  }
}