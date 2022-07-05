#include <bits/extc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> event(n);
  for (auto &x : event) cin >> x.second >> x.first;
  sort(begin(event), end(event));
  multiset<int> mts;
  int ans = 0;
  for (int i = 0; i < k; ++i) mts.insert(0);
  for (auto e : event) {
    auto itr = mts.upper_bound(e.second);
    if (itr == begin(mts)) continue;
    mts.erase(--itr);
    mts.insert(e.first);
    ++ans;
  }
  cout << ans;
}