#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  const int MAX_N = 3e5 + 1;
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> pref_cnt(MAX_N), pref_sum(MAX_N);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++pref_cnt[x];
    pref_sum[x] += x;
  }
  partial_sum(begin(pref_cnt), end(pref_cnt), begin(pref_cnt));
  partial_sum(begin(pref_sum), end(pref_sum), begin(pref_sum));
  ll ans = 1;
  for (int x = 2; x < MAX_N; ++x) {
    int l = 0, r = x;
    ll cost = 0;
    while (l < MAX_N) {
      ll count = pref_cnt[min(r, MAX_N - 1)] - pref_cnt[l];
      ll total = pref_sum[min(r, MAX_N - 1)] - pref_sum[l];
      cost += r * count - total;
      l += x, r += x;
    }
    if (cost <= k) ans = x;
  }
  ll mx_cost = 1ll * MAX_N * n - pref_sum.back();
  if (mx_cost <= k) ans = 1ll * MAX_N + (k - mx_cost) / n;
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}