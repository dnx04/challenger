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
    priority_queue<int, vector<int>, greater<int>> pq;
    int odd = 0, even = 0;
    for (int i = 0; i < 2 * n; ++i) {
      int x;
      cin >> x;
      int p2 = 0;
      while (x % 2 == 0) {
        x /= 2;
        ++p2;
      }
      if (p2)
        pq.push(p2), ++even;
      else
        ++odd;
    }
    if (odd > even)
      cout << (odd - even) / 2 << '\n';
    else {
      int ans = 0, t = (even - odd) / 2;
      while (t) {
        ans += pq.top();
        pq.pop();
        --t;
      }
      cout << ans << '\n';
    }
  }
}