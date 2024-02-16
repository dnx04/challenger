#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  ll c;
  cin >> n >> m >> c;
  vector<vector<ll>> a(n, vector<ll>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  auto flip = [&](vector<vector<ll>> &a) {
    // flip the board horizontally
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m / 2; j++) {
        swap(a[i][j], a[i][m - 1 - j]);
      }
    }
  };
  const ll INF = 1e18;
  auto cal = [&](vector<vector<ll>> &a) {
    int n = a.size(), m = a[0].size();
    ll ans = INF;
    vector<vector<ll>> dp1(n, vector<ll>(m, INF)), dp2(n, vector<ll>(m, INF));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        dp1[i][j] = min(dp1[i][j], a[i][j]);
        if (i) dp1[i][j] = min(dp1[i][j], dp1[i - 1][j] + c);
        if (j) dp1[i][j] = min(dp1[i][j], dp1[i][j - 1] + c);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i) dp2[i][j] = min(dp2[i][j], dp1[i - 1][j] + c + a[i][j]);
        if (j) dp2[i][j] = min(dp2[i][j], dp1[i][j - 1] + c + a[i][j]);
        ans = min(ans, dp2[i][j]);
      }
    }
    return ans;
  };
  ll r1 = cal(a);
  flip(a);
  ll r2 = cal(a);
  cout << min(r1, r2);
}