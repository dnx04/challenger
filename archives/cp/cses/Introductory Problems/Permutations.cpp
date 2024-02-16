#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  if (1 < n && n < 4)
    cout << "NO SOLUTION";
  else {
    for (int i = 0; i < n / 2; ++i) {
      cout << n / 2 + i + 1 << ' ' << i + 1 << ' ';
    }
    if (n & 1) cout << n;
  }
}