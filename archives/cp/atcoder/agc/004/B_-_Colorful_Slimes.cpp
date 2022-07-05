#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &v : a) cin >> v;
  vector<vector<int>> mn(n, vector<int>(n, 1e9));
  for (int i = 0; i < n; ++i) mn[i][0] = a[i];
  for (int i = 0; i < n; ++i) {
    for (int k = 1; k < n; ++k) {
      mn[i][k] = min(mn[i][k - 1], a[(i - k + n) % n]);
    }
  }
  long long ans = 1e18;
  for (int k = 0; k < n; ++k) {
    long long sum = 0;
    for (int i = 0; i < n; ++i) sum += mn[i][k];
    ans = min(ans, 1ll * k * x + sum);
  }
  cout << ans;
}