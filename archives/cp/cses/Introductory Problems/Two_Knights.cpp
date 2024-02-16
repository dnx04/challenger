#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int k;
  cin >> k;
  for (int n = 1; n <= k; n++) {
    cout << 1ll * n * n * (n * n - 1) / 2 - 4 * (n - 1) * (n - 2) << '\n';
  }
}