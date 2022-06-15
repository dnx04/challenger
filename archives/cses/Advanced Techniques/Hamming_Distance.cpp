#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  bitset<30> bs;
  for (auto &x : a) {
    cin >> bs;
    x = bs.to_ulong();
  }
  int ans = 31;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ans = min(ans, __builtin_popcount(a[i] ^ a[j]));
    }
  }
  cout << ans;
}