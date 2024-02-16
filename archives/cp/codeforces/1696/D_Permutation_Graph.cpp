#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  int n;
  cin >> n;
  vector<int> a(n + 2), min_pre(n + 2, n), max_pre(n + 2), min_suf(n + 2, n),
      max_suf(n + 2), pos(n + 2);
  for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]] = i;
  for (int i = 1; i <= n; ++i) {
    min_pre[i] = min(min_pre[i - 1], a[i]);
    max_pre[i] = max(max_pre[i - 1], a[i]);
    min_suf[n - i + 1] = min(min_suf[n - i + 2], a[n - i + 1]);
    max_suf[n - i + 1] = max(max_suf[n - i + 2], a[n - i + 1]);
  }
  auto solve = [&](auto solve, int l, int r) {
    if (l == r) return 0;
    int mx = (l == 1 ? max_pre[r] : max_suf[l]);
    int mn = (l == 1 ? min_pre[r] : min_suf[l]);
    int pmx = pos[mx], pmn = pos[mn];
    if (pmx < pmn) swap(pmx, pmn);
    int res = 1;
    if(l == 1) res += solve(solve, 1, pmn);
    if(r == n) res += solve(solve, pmx, n);
    return res;
  };
  cout << solve(solve, 1, n) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}