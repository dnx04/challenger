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
    if ((a + b) % 3 == 0 && (2 * a >= b) && (2 * b >= a) &&
        (2 * b - a) / 3 + (2 * a - b) / 3 == (a + b) / 3)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}