#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int64_t n;  // will overflow if n is not 64-bit integer
  cin >> n;
  while (true) {
    cout << n << ' ';
    if (n == 1) break;
    if (n & 1)
      n = n * 3 + 1;
    else
      n >>= 1;
  };
}