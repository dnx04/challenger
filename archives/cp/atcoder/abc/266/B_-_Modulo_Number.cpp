#include <bits/extc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  const ll mod = 998244353;
  ll n;
  cin >> n;
  cout << ((n % mod) + mod) % mod;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}