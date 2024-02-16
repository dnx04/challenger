#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  vector<int> pre(a), suf(a);
  for (int i = 1; i <= n; ++i) pre[i] = gcd(pre[i - 1], a[i]);
  for (int i = n; i >= 1; --i) suf[i] = gcd(suf[i + 1], a[i]);
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans = max(ans, gcd(pre[i - 1], suf[i + 1]));
  cout << ans;
}