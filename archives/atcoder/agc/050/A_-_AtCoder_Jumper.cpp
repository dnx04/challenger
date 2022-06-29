#include "bits/extc++.h"

using namespace std;

#ifdef LOCAL
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cout << (2 * i) % n + 1 << ' ' << (2 * i + 1) % n + 1 << '\n';
}