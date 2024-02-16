#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  const int N = 3000;
  const ll INF = numeric_limits<ll>::max();
  vector<ll> a(N + 1), dp(N + 1), ndp(N + 1);

  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];

  auto C = [&](int i, int j) { return (a[j] - a[i - 1]) * (a[j] - a[i - 1]); };
  for (int i = 1; i <= n; ++i) dp[i] = C(1, i);

  auto dnc = [&](auto dnc, int l, int r, int optl, int optr) {
    if (l > r) return;

    int mid = (l + r) >> 1;
    pair<ll, ll> best = {INF, -1};

    for (int k = optl; k <= min(mid, optr); k++) {
      best = min(best, {(k ? dp[k - 1] : 0) + C(k, mid), k});
    }

    ndp[mid] = best.first;
    int opt = best.second;

    dnc(dnc, l, mid - 1, optl, opt);
    dnc(dnc, mid + 1, r, opt, optr);
  };
  for (int i = 1; i < k; ++i) dnc(dnc, 1, n, 1, n), dp = ndp;
  cout << dp[n];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}