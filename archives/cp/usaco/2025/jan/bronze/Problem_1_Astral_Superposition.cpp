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
  int n, A, B;
  cin >> n >> A >> B;
  swap(A, B);
  vector<vector<int>> a(n, vector<int>(n));
  rep(i, 0, n) rep(j, 0, n) {
    char c;
    cin >> c;
    if (c == 'W') a[i][j] = 0;
    if (c == 'G') a[i][j] = 1;
    if (c == 'B') a[i][j] = 2;
  }

  ll ans = 0;
  if (A == 0 && B == 0) {
    rep(i, 0, n) rep(j, 0, n) {
      if (a[i][j] >= 1) {
        ++ans;
      }
    }
    cout << ans << '\n';
    return;
  }
  vector<vi> b(n, vi(n, -1));
  rep(i, 0, n) rep(j, 0, n) {
    if (i < A || j < B) {
      b[i][j] = (a[i][j] == 1);
      if (a[i][j] == 2) {
        cout << -1 << '\n';
        return;
      }
    }
  }
  for (int i = 0; i + A < n; ++i) {
    for (int j = 0; j + B < n; ++j) {
      if (a[i + A][j + B] == 0) {
        if (b[i][j] == -1) b[i][j] = 0;
        b[i + A][j + B] = 0;
      } else if (a[i + A][j + B] == 1) {
        if (b[i][j] == 0) b[i + A][j + B] = 1;
        if (b[i][j] == 1) b[i + A][j + B] = 0;
      } else {
        if (a[i][j] == 0) {
          cout << -1 << '\n';
          return;
        }
        b[i][j] = 1;
        b[i + A][j + B] = 1;
      }
    }
  }
  rep(i, 0, n) rep(j, 0, n) {
    if (b[i][j] == -1) {
      cout << -1 << '\n';
      return;
    }
    ans += b[i][j];
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
