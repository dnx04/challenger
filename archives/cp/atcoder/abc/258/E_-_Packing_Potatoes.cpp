#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, q;
  ll x;
  cin >> n >> q >> x;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  ll tot = accumulate(begin(a), end(a), 0ll);
  const ll fi = x / tot, se = x % tot;
  vector<ll> f(n);
  ll sum = 0;
  for (int i = 0, j = 0, cnt = 0; i < n; ++i) {
    while (sum < se) {
      sum += a[j];
      j = (j + 1) % n;
      ++cnt;
    }
    f[i] = fi * n + cnt;
    sum -= a[i];
    --cnt;
  }
  // build the binary lifting array of nxt
  const int k = 40;
  vector<vector<int>> up(k, vector<int>(n));
  for (int i = 0; i < n; ++i) up[0][i] = (i + f[i]) % n;
  for (int i = 1; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      up[i][j] = up[i - 1][up[i - 1][j]];
    }
  }
  auto lift = [&](int u, ll step) {
    for (int i = k - 1; i >= 0; --i) {
      if ((step >> i) & 1) u = up[i][u];
    }
    return u;
  };
  while (q--) {
    ll x;
    cin >> x;
    cout << f[lift(0, x - 1)] << '\n';
  }
}