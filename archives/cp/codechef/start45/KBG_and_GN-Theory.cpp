#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

#define int long long

auto sieve = [](int n) {
  vector<int> lpf(n + 1);
  iota(begin(lpf), end(lpf), 0);
  for (int i = 2; i <= n; ++i) {
    if (lpf[i] == i) {
      for (int j = 1ll * i * i; j <= n; j += i) {
        if (lpf[j] == j) lpf[j] = i;
      }
    }
  }
  return lpf;
};

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  const int N = 1e5;
  auto lpf = sieve(N);
  vector<int> d(N + 1);
  d[1] = 0;
  for (int i = 1; i <= N; ++i) d[i] = d[i / lpf[i]] + lpf[i];

  int tc;
  cin >> tc;
  while (tc--) {
    int n, q;
    cin >> n >> q;
    while (q--) {
      int u, v;
      cin >> u >> v;
      int g = gcd(u, v);
      cout << d[u] + d[v] - 2 * d[g] << '\n';
    }
  }
}