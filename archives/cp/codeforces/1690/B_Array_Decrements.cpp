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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    set<int> diff;
    int mx0 = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      if (b[i] == 0)
        mx0 = max(mx0, a[i]);
      else
        diff.insert(a[i] - b[i]);
    }
    int op = max(*begin(diff), mx0);
    for (int i = 0; i < n; ++i) a[i] = max(a[i] - op, 0);
    cout << ((a == b) ? "yes\n" : "no\n");
  }
}