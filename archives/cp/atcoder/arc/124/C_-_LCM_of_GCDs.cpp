#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  map<tuple<ll, ll, int>, ll> dp;
  auto rec = [&](auto rec, ll x, ll y, int p = 0) {
    if (dp.count({x, y, p})) return dp[{x, y, p}];
    auto &res = dp[{x, y, p}];
    if (p == n)
      return res = x * y / gcd(x, y);
    else
      res = max({res, rec(rec, gcd(x, b[p]), gcd(y, a[p]), p + 1),
                 rec(rec, gcd(x, a[p]), gcd(y, b[p]), p + 1)});
    return res;
  };
  cout << rec(rec, 0, 0);
}