#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

map<ll, ll> dp;

ll f(ll n) {
  if (n == 0) return 0;
  if (dp.count(n)) return dp[n];
  if (n & 1) return dp[n] = 2 * f(n / 2) + n / 2 + 1;
  return dp[n] = f(n / 2) + f(n / 2 - 1) + n / 2;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  ll n;
  cin >> n;
  cout << f(n);
}