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
    int n, xor_array = 0;
    cin >> n;
    vector<int> a(n + 1), ans;
    for (auto &v : a) cin >> v, xor_array ^= v;
    if (n & 1) {
      int idx = 0;
      for (int i = 0; i <= n; ++i) {
        if (xor_array == a[i]) {
          idx = i;
          break;
        }
      }
      for (int i = 0; i <= n; ++i)
        if (i != idx) ans.push_back(a[i] ^ xor_array);
    } else {
      for (int i = 1; i <= n; ++i) ans.push_back(a[0] ^ a[i]);
    }
    for (auto v : ans) cout << v << ' ';
    cout << '\n';
  }
}