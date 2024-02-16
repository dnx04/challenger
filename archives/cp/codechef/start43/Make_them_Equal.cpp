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
    int64_t a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i <= 32; ++i) {
      int ba = (a >> i) & 1;
      int bb = (b >> i) & 1;
      int bc = (c >> i) & 1;
      if (ba == bb && bb == bc)
        break;
      else if (ba == 0 && bb == 0 && bc == 1)
        c += (1ll << i);
      else if (ba == 0 && bb == 1 && bc == 0)
        b += (1ll << i);
      else if (ba == 1 && bb == 0 && bc == 0)
        a += (1ll << i);
      else if (ba == 0 && bb == 1 && bc == 1)
        a += (1ll << i);
      else if (ba == 1 && bb == 0 && bc == 1)
        b += (1ll << i);
      else if (ba == 1 && bb == 1 && bc == 0)
        c += (1ll << i);
    }
    if (a == b && b == c)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}