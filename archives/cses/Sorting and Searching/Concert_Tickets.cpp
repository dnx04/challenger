#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define _GLIBCXX_ASSERTIONS
#endif

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  multiset<int> mts;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mts.insert(x);
  }
  while (m--) {
    int x;
    cin >> x;
    auto itr = mts.upper_bound(x);
    if (itr == begin(mts))
      cout << -1 << '\n';
    else {
      cout << *(--itr) << '\n';
      mts.erase(itr);
    }
  }
}