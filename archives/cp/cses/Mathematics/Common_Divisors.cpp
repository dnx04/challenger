#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  const int N = 1e6 + 1;
  vector<int> occ(N);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++occ[x];
  }
  for (int g = N - 1; g > 0; --g) {
    int cnt = 0;
    for (int i = g; i <= N - 1; i += g) cnt += occ[i];
    if (cnt >= 2) return cout << g, 0;
  }
}