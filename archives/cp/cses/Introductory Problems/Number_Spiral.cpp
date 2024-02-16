#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      if (a % 2 == 0)
        cout << 1ll * a * a - b + 1 << '\n';
      else
        cout << 1ll * (a - 1) * (a - 1) + b << '\n';
    } else {
      if (b % 2 == 0)
        cout << 1ll * (b - 1) * (b - 1) + a << '\n';
      else
        cout << 1ll * b * b - a + 1 << '\n';
    }
  }
}