#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto &x : a) cin >> x;
    int64_t sum = accumulate(begin(a), end(a), 0ll) / (n + 1);
    for(auto v: a) cout << v - sum << ' ';
    cout << '\n';
  }
}