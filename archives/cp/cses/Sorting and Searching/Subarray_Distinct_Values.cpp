#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  map<int, int> cnt;
  int64_t ans = 0;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  for (int l = 0, r = 0, uniq = 0; l < n; ++l) {
    while (r < n) {
      ++cnt[a[r]];
      if (cnt[a[r]] == 1) ++uniq;
      if (uniq > k) {
        --cnt[a[r]], --uniq;
        break;
      }
      ++r;
    }
    ans += r - l;
    --cnt[a[l]];
    if (cnt[a[l]] == 0) --uniq;
  }
  cout << ans;
}