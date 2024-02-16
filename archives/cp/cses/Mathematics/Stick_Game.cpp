#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  const int N = 1e6 + 1;
  int n, k;
  cin >> n >> k;
  bitset<N> dp;
  vector<int> mv(k);
  for (auto &x : mv) cin >> x;
  for (int i = 1; i <= n; ++i) {
    for (auto x : mv) {
      if (i - x >= 0) {
        dp[i] = dp[i] | !dp[i - x];
      }
    }
  }
  for (int i = 1; i <= n; ++i) cout << (dp[i] ? "W" : "L");
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}