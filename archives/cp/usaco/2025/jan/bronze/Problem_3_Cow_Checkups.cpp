#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo-ng/prettyprint.hpp"
#endif

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  int n;
  cin >> n;
  vi a(n), b(n), pre(n), suf(n), ans(n + 1);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  rep(i, 0, n) {
    pre[i] = (i ? pre[i - 1] : 0) + (a[i] == b[i]);
    suf[n - i - 1] = (i ? suf[n - i] : 0) + (a[n - i - 1] == b[n - i - 1]);
  }
  vector<vi> dp(n, vi(n));
  for(int i = 0; i < n; ++i) {
    dp[i][i] = (a[i] == b[i]);
    if(i + 1 < n) {
      dp[i][i + 1] += (a[i] == b[i + 1]);
      dp[i][i + 1] += (a[i + 1] == b[i]);
    }
  }
  for(int len = 1; len <= n; ++len) {
    for(int i = 0; i + len - 1 < n; ++i) {
      int j = i + len - 1;
      if(i && j < n - 1) {
        dp[i - 1][j + 1] += dp[i][j];
        dp[i - 1][j + 1] += (a[i - 1] == b[j + 1]);
        dp[i - 1][j + 1] += (a[j + 1] == b[i - 1]);
      }
    }
  }
  // for(int i = 0; i < n; ++i) {
  //   for(int j = i; j < n; ++j) {
  //     cerr << i << ' ' << j << ' ' << dp[i][j] << '\n';
  //   }
  // }
  for(int sum = 0; sum < 2 * n; ++sum) {
    for(int l = 0; l < n; ++l) {
      int r = sum - l;
      if(l <= r && r < n) {
        int res = 0;
        if(l) res += pre[l - 1];
        if(r < n - 1) res += suf[r + 1];
        res += dp[l][r];
        ++ans[res];
      }
    }
  }
  rep(i, 0, n + 1) cout << ans[i] << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
