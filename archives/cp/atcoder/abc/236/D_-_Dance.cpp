#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  n *= 2;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) cin >> a[i][j];

  vector<bool> matched(n);
  int ans = 0;
  auto rec = [&](auto rec, int pr = 0, int res = 0) {
    if (2 * pr == n) {
      ans = max(ans, res);
      return;
    }
    int pick = 0;
    for (int i = 0; i < n; ++i) {
      if (!matched[i]) {
        pick = i;
        break;
      }
    }
    matched[pick] = true;
    for (int j = pick + 1; j < n; ++j) {
      if (!matched[j]) {
        matched[j] = true;
        rec(rec, pr + 1, res ^ a[pick][j]);
        matched[j] = false;
      }
    }
    matched[pick] = false;
  };
  rec(rec);
  cout << ans;
}