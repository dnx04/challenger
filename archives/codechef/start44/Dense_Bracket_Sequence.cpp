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
    string s;
    int n;
    cin >> n >> s;
    s = '0' + s;
    s += '0';
    vector<int> pref(n + 2), suff(n + 2);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + (s[i] == '(');
    for (int i = n; i >= 1; --i) suff[i] = suff[i + 1] + (s[i] == ')');
    int ans = n;
    for (int i = 0; i <= n; ++i) {
      ans = min(ans, n - 2 * min(pref[i], suff[i + 1]));
    }
    cout << ans << '\n';
  }
}