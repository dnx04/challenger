#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = n - 1; j >= 0; --j) {
      cout << (((i ^ (i >> 1)) >> j) & 1);
    }
    cout << '\n';
  }
}