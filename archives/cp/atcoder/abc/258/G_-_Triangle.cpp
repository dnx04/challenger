#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  const int N = 3000;
  int n;
  cin >> n;
  bitset<N> bs[N];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char ch;
      cin >> ch;
      if (j > i) bs[i][j] = ch - '0';
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (bs[i][j]) {
        ans += (bs[i] & bs[j]).count();
      }
    }
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}