#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  using ld = long double;
  int n, k;
  cin >> n >> k;

  ld ans = 0;
  for (int i = 1; i <= k; ++i) {
    ans += i * (powl(ld(i) / ld(k), n) - powl(ld(i - 1) / ld(k), n));
  }
  cout << fixed << setprecision(6) << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}