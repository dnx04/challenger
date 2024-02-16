#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  map<pair<int, int>, int64_t> cnt;
  for (int i = 0; i < n; ++i) {
    long double x;
    cin >> x;
    int64_t xi = llround(x * 1e9);
    int c2 = 0, c5 = 0;
    while (xi % 2 == 0) ++c2, xi /= 2;
    while (xi % 5 == 0) ++c5, xi /= 5;
    cnt[{c2, c5}]++;
  }
  int64_t ans = 0;
  for (auto c1 : cnt) {
    for (auto c2 : cnt) {
      int cnt2 = c1.first.first + c2.first.first;
      int cnt5 = c1.first.second + c2.first.second;
      if (cnt2 >= 18 && cnt5 >= 18) {
        int q2 = c1.second, q5 = c2.second;
        if (c1 < c2)
          ans += q2 * q5;
        else if (c1 == c2)
          ans += (q2 - 1) * q2 / 2;
      }
    }
  }
  cout << ans;
}