#include <bits/extc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> event(n);
  for (auto &x : event) cin >> x.second >> x.first;
  sort(begin(event), end(event));
  int now = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    if (now <= event[i].second) ++ans, now = event[i].first;
  }
  cout << ans;
}