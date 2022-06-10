#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(begin(a), end(a));
  int i1 = 0, i2 = n - 1;
  while (i1 < i2) {
    if (a[i1].first + a[i2].first < k)
      ++i1;
    else if (a[i1].first + a[i2].first > k)
      --i2;
    else
      return cout << a[i1].second << ' ' << a[i2].second << '\n', 0;
  }
  cout << "IMPOSSIBLE";
}