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
    int n, x;
    cin >> n >> x;
    string s = string(n, 'a');
    int cnt = 1;
    for (int l = 1, r = n - 2; l <= r; ++l, --r) {
      if (cnt < x) {
        s[l] = 'a' + cnt;
        s[r] = s[l];
        ++cnt;
      }
    }
    if(cnt < x) cout << -1 << '\n';
    else cout << s << '\n';
  }
}