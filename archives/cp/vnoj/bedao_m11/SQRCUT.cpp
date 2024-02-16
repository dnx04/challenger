#include "bits/extc++.h"

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#ifdef DEBUG
#include "tools/prettyprint.hpp"
#endif

long long rec(int a, int b) {
  if (a == b || b == 0) return 0;
  if (a < b) swap(a, b);
  return (a + b - 1) / b - 1 + rec(b, a % b);
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b;
    cin >> a >> b;
    cout << rec(a, b) << '\n';
  }
}