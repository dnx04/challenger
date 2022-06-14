#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

auto sieve = [](int n) {
  vector<int> lpf(n + 1);
  iota(begin(lpf), end(lpf), 0);
  for (int i = 2; i <= n; ++i) {
    if (lpf[i] == i) {
      for (long long j = 1ll * i * i; j <= n; j += i) {
        lpf[j] = i;
      }
    }
  }
  return lpf;
};

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int q;
  cin >> q;
  vector<int> lpf = sieve(1e6 + 1);
  while (q--) {
    int x;
    cin >> x;
    int ans = 1;
    while (x > 1) {
      int cnt = 0, p = lpf[x];
      while (x % p == 0) x /= p, ++cnt;
      ans *= (cnt + 1);
    }
    cout << ans << '\n';
  }
}