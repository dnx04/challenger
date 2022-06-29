#include "bits/extc++.h"

using namespace std;

#ifdef LOCAL
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &v : a) cin >> v;
  vector<int> cnt_bit(32);
  for (auto v : a) {
    for (int i = 0; i < 30; ++i) cnt_bit[i] += (v >> i) & 1;
  }
  for (int t = 0; t < 30; ++t) {
    int pick = -1;
    long long max_gain = 0;
    for (int i = 0; i < n; ++i) {
      long long sum = 0;
      for (int j = 0; j < 30; ++j) {
        sum += (1ll << j) * ((a[i] >> j) & 1) * (n - 2 * cnt_bit[j]);
      }
      if (sum > max_gain) {
        max_gain = sum;
        pick = a[i];
      }
    }
    if (pick == -1) break;
    for (int i = 0; i < 30; ++i) {
      if ((pick >> i) & 1) cnt_bit[i] = n - cnt_bit[i];
    }
    for(auto &x: a) x ^= pick;
  }
  cout << accumulate(a.begin(), a.end(), 0ll) << '\n';
}