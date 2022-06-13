#include <bits/extc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> house(n), buyer(m);
  for (auto &x : house) cin >> x;
  for (auto &x : buyer) cin >> x;
  sort(begin(house), end(house));
  sort(begin(buyer), end(buyer));
  
  int ans = 0;
  for (int i = 0, j = 0; i < n && j < m;) {
    int diff = house[i] - buyer[j];
    if (abs(diff) <= k)
      ++i, ++j, ++ans;
    else {
      if (diff > k)
        ++j;
      else
        ++i;
    }
  }
  cout << ans;
}