#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  ll n;
  cin >> n;
  ll ans = 1e18;
  for (ll a = 0; a <= 1e6; ++a) {
    ll l = 0, r = 1e6;
    while (l <= r) {
      ll b = (l + r) / 2;
      if ((a + b) * (a * a + b * b) >= n) {
        ans = min(ans, (a + b) * (a * a + b * b));
        r = b - 1;
      } else {
        l = b + 1;
      }
    }
  }
  cout << ans;
}