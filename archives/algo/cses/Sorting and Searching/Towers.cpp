#include <bits/extc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  multiset<int> mts;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    auto itr = mts.upper_bound(x);
    if(itr != end(mts)) mts.erase(itr);
    mts.insert(x);
  }
  cout << mts.size();
}