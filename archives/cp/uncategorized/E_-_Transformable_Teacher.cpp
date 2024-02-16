#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n + 2), pre(n + 2), suf(n + 2);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a.begin() + 1, a.begin() + n + 1);
  for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + (i & 1 ? -a[i] : a[i]);
  for (int i = n; i >= 1; --i) suf[i] = suf[i + 1] + (i & 1 ? a[i] : -a[i]);
  ll ans = 1e18;
  for (int i = 0; i < m; ++i) {
    int w;
    cin >> w;
    int itr = lower_bound(a.begin() + 1, a.begin() + n + 1, w) - a.begin();
    int l = max(itr - 2, 1);
    int r = min(itr + 2, n);
    for (int i = l; i <= r; ++i) {
      ans = min(ans, pre[i - 1] + llabs(w - a[i]) + suf[i + 1]);
    }
  }
  cout << ans;
}