#include "bits/stdc++.h"

using namespace std;

using ll = long long;

signed main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<ll> d(n);
    for (auto &x : d) cin >> x;
    int ans = 0;
    while (!d.empty()) {
      n = d.size();
      if (n >= 2) {
        if (d[n - 2] < d[n - 1]) {
          d[n - 2] += d[n - 1];
        } else {
          ++ans;
        }
      } else {
        ++ans;
      }
      d.pop_back();
    }
    cout << ans << '\n';
  }
}