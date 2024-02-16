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
  for (int i3 = 1; i3 < n - 1; ++i3) {
    int i1 = 0, i2 = n - 1;
    while (i1 < i3 && i3 < i2) {
      int targ = k - a[i3].first;
      if (a[i1].first + a[i2].first == targ) {
        cout << a[i1].second << ' ' << a[i2].second << ' ' << a[i3].second;
        return 0;
      }
      if (a[i1].first + a[i2].first < targ)
        ++i1;
      else
        --i2;
    }
  }
  cout << "IMPOSSIBLE";
}