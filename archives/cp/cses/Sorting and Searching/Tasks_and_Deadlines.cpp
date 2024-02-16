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
  for (auto &e : event) cin >> e.first >> e.second;
  sort(begin(event), end(event));
  long long ans = 0, now = 0;
  for (auto e : event) {
    now += e.first;
    ans += e.second - now;
  }
  cout << ans;
}