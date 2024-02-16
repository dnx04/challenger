#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int l = 0, r = 0, ans = 0;
  map<int, bool> chk;
  while (l < n) {
    while (r < n && !chk[a[r]]) chk[a[r]] = true, ++r;
    ans = max(ans, r - l);
    chk[a[l]] = false, ++l;
  }
  cout << ans;
}