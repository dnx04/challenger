#include "bits/extc++.h"

using namespace std;

#ifdef LOCAL
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &v : a) cin >> v;
  for (auto &v : b) cin >> v;
  multiset<int> ma(begin(a), end(a)), mb(begin(b), end(b));
  if (ma != mb)
    cout << "No";
  else {
    int cnt_inva = 0, cnt_invb = 0;
    bool is_duplicate = false;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        cnt_inva += (a[i] > a[j]);
        cnt_invb += (b[i] > b[j]);
        is_duplicate |= (a[i] == a[j]);
      }
    }
    if ((cnt_inva % 2 == cnt_invb % 2) || is_duplicate)
      cout << "Yes";
    else
      cout << "No";
  }
}