#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  string s;
  cin >> s;
  vector<ll> cm(3), cx(3);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'X') ++cx[a[i]];
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'E') {
      if (a[i] == 0) {
        ans += cm[0] * cx[0] + cm[0] * cx[2] + cm[2] * cx[0] +
               cm[2] * cx[2];                        // mex = 1
        ans += 2 * (cm[1] * cx[0] + cm[0] * cx[1] + cm[1] * cx[1]);  // mex = 2
        ans += 3 * (cm[2] * cx[1] + cm[1] * cx[2]);  // mex = 3
      } else if (a[i] == 1) {
        ans += 2 * (cm[1] * cx[0] + cm[0] * cx[1] + cm[0] * cx[0]);  // mex = 2
        ans += 3 * (cm[2] * cx[0] + cm[0] * cx[2]);                  // mex = 3
      } else {
        ans += cm[0] * cx[0] + cm[0] * cx[2] + cm[2] * cx[0];  // mex = 1
        ans += 3 * (cm[0] * cx[1] + cm[1] * cx[0]);            // mex = 3
      }
    }
    if (s[i] == 'M') ++cm[a[i]];
    if (s[i] == 'X') --cx[a[i]];
  }
  cout << ans;
}