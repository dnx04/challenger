#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  using ll = long long;
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    ll c = 1;
    for (ll p = 9;; n -= p, ++c, p = 9 * pow(10, c - 1) * c) {
      if (n - p <= 0) break;
    }
    n--;
    ll x = n / c;
    ll y = n % c;
    ll ans = x + (ll)pow(10, c - 1);
    string s = std::to_string(ans);
    cout << s[y] << endl;
  }
}