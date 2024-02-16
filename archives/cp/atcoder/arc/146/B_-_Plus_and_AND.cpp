#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n, k;
  ll m;
  cin >> n >> m >> k;
  vector<ll> a(n), need(n);
  int ans = 0;
  for (auto &x : a) cin >> x;
  for (int st = 30; st >= 0; --st) {
    auto nneed = need, na = a;
    for (int i = 0; i < n; ++i) {
      if (a[i] >> st & 1) continue;
      ll add = (1 << st) - (a[i] % (1 << st));
      nneed[i] += add, na[i] += add;
    }
    auto cost = nneed;
    nth_element(begin(cost), begin(cost) + k, end(cost));
    ll sum = 0;
    for(int i = 0; i < k; ++i) sum += cost[i];
    if (sum <= m) ans |= (1 << st), a = na, need = nneed;
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