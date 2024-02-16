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
    set<pair<int, int>> s;
    for (int64_t i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        s.insert({i, n - i}), s.insert({n - i, i});
        if (i != 1) s.insert({n / i, n - n / i}), s.insert({n - n / i, n / i});
      }
    }
    cout << s.size() << '\n';
  }
}