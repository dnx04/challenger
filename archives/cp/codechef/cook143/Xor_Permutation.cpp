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
    int n;
    cin >> n;
    if (n == 3)
      cout << -1 << '\n';
    else if (n == 4)
      cout << "1 2 4 3 \n";
    else {
      cout << "5 1 2 4 3 ";
      if (n == 5) cout << '\n';
      for (int i = 6; i <= n; ++i) cout << i << " \n"[i == n];
    }
  }
}
