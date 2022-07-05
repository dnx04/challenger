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
    for (int i = 1, j = n, t = 0; t < n; ++t) {
      if (t & 1)
        cout << i++ << ' ';
      else
        cout << j-- << ' ';
    }
    cout << '\n';
  }
}