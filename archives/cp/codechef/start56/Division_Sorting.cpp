#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  const int mxA = 5e5 + 1;
  vector<int> p(mxA);
  vector<vector<int>> div(mxA, vector<int>({1}));
  for (int i = 2; i < mxA; ++i) {
    for (int j = i; j < mxA; j += i) div[j].push_back(i);
    if (p[i] == 0) {
      for (int j = i; j < mxA; j += i) {
        int tmp = j;
        while (tmp % i == 0) ++p[j], tmp /= i;
      }
    }
  }
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(n + 1, 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    const int inf = 1e9, sz = 210;
    array<int, sz> dp{};
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      array<int, sz> ndp{};
      auto &prv = div[a[i - 1]];
      auto &cur = div[a[i]];
      int mn = inf;
      ans = inf;
      for (int p1 = 0, p2 = 0; p1 < (int)cur.size(); ++p1) {
        while (p2 < (int)prv.size() && prv[p2] <= cur[p1]) {
          mn = min(mn, dp[p2]);
          ++p2;
        }
        ndp[p1] = mn + p[a[i] / cur[p1]];
        ans = min(ans, ndp[p1]);
      }
      dp = move(ndp);
    }
    cout << ans << '\n';
  }
}