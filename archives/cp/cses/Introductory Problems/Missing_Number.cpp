#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  const int N = 2e5 + 1;
  bitset<N> chk;
  for (int i = 0; i < n - 1; ++i) {
    int x;
    cin >> x;
    chk[x] = true;
  }
  for (int i = 1; i <= n; ++i) {
    if (!chk[i]) {
      cout << i;
      break;
    }
  }
}