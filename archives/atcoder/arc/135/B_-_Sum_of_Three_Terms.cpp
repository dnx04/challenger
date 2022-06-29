#include "bits/extc++.h"

using namespace std;

#ifdef LOCAL
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int64_t> s(n + 1), a(n + 3);
  for (int i = 1; i <= n; ++i) cin >> s[i];
  a[1] = a[2] = 0;
  for (int i = 1; i <= n; ++i) a[i + 2] = s[i] - a[i] - a[i + 1];

  int64_t mna = 0, mnb = 0, mxab = 1e9;
  for (int i = 1; i <= n + 2; i += 3) {
    mna = max(mna, -a[i]);
    if (i + 1 <= n + 2) mnb = max(mnb, -a[i + 1]);
    if (i + 2 <= n + 2) mxab = min(mxab, a[i + 2]);
  }
  if (mna + mnb > mxab) {
    cout << "No";
  } else {
    cout << "Yes\n";
    for (int i = 1; i <= n + 2; ++i) {
      if (i % 3 == 1)
        cout << a[i] + mna << ' ';
      else if (i % 3 == 2)
        cout << a[i] + mnb << ' ';
      else
        cout << a[i] - mna - mnb << ' ';
    }
  }
}