#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  multiset<int> mts;
  vector<int> a(n);
  for (auto &v : a) cin >> v;
  sort(begin(a), end(a));
  int ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    bool matched = false;
    for (int k = 30; k >= 0; --k) {
      auto itr = mts.find((1 << k) - a[i]);
      if (itr != end(mts)) {
        mts.erase(itr);
        ++ans, matched = true;
        break;
      }
    }
    if (!matched) mts.insert(a[i]);
  }
  cout << ans;
}