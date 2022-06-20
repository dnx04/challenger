#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) a.push_back(a[i]);
    for (int i = 1; i < 2 * n; ++i) a[i] ^= a[i - 1];
    map<int64_t, int> mp;
    int ans = 0, cur = 0;
    for (int i = 0; i < 2 * n; ++i) {
      ++mp[a[i]];
      if (mp[a[i]] == 1) ++cur;
      if (i >= n) {
        --mp[a[i - n]];
        if (mp[a[i - n]] == 0) --cur;
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
}