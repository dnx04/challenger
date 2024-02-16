#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "tools/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int kek = 0;
    while (kek * kek < n) ++kek;
    vector<int> ans(n);
    set<int> s;
    for (int i = n - 1; i >= 0; --i) {
      while (kek * kek - i >= n || s.count(kek * kek - i)) --kek;
      ans[i] = kek * kek - i;
      s.insert(ans[i]);
    }
    for (auto v : ans) cout << v << ' ';
    cout << '\n';
  }
}