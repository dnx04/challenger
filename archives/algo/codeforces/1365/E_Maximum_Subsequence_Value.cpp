#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "lib/prettyprint.hpp"
#endif

#define int long long

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  // calculate trio or ?
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int ans = 0;
  if (n <= 3) {
    for (int i = 0; i < n; ++i) ans |= a[i];
    cout << ans;
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          ans = max(ans, a[i] | a[j] | a[k]);
        }
      }
    }
    cout << ans;
  }
}