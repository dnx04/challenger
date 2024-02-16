#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto& x : a) cin >> x;
  vector<ll> pre(a);
  partial_sum(begin(pre), end(pre), begin(pre));
  auto get = [&](int l, int r) {
    if (l == 0) return pre[r];
    return pre[r] - pre[l - 1];
  };
  ll ans = -1e18, sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += min(i + 1, m) * a[i];
    if (i >= m) sum -= get(i - m, i - 1);
    if (i >= m - 1) ans = max(ans, sum);
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