#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    ll g = 0;
    vector<int> a(n);
    for (auto &x : a) cin >> x, g = gcd(g, x);
    int cnt = 0;
    for (int i = 0, gg = 0; i < n; ++i) {
      gg = gcd(gg, a[i]);
      if (gg == g) ++cnt, gg = 0;
    }
    cout << (cnt >= k ? "YES" : "NO") << '\n';
  }
}