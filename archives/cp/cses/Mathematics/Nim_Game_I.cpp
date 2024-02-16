#include "bits/extc++.h"

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#ifdef DEBUG
#include "tools/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int xs = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      xs ^= x;
    }
    cout << (xs ? "first\n" : "second\n");
  }
}