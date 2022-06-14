#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int h1 = n / 3 + 1; h1 < n; ++h1) {
      int h2 = (n - h1) / 2, h3 = n - h1 - h2;
      while (h2 <= h3) ++h2, --h3;
      if (h1 > h2 && h2 > h3 && h3 > 0) {
        cout << h2 << ' ' << h1 << ' ' << h3 << '\n';
        break;
      }
    }
  }
}