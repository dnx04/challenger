#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
      char ch;
      cin >> ch;
      a[i] = a[i - 1] + (ch == 'W');
    }
    int ans = n;
    for (int i = 0; i + k <= n; ++i) {
      ans = min(ans, a[i + k] - a[i]);
    }
    cout << ans << '\n';
  }
}