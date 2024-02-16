#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  set<pair<ll, int>> s;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > 0) s.insert({a[i], i});
  }
  ll minus = 0;
  while (!s.empty()) {
    auto [x, i] = *s.begin();
    x -= minus;
    if (x > 0) {
      if (k >= x * int(s.size())) {
        k -= x * int(s.size());
        minus += x;
      } else {
        minus += k / int(s.size());
        k %= int(s.size());
        break;
      }
    }
    s.erase(s.begin());
  }
  for (int i = 0; i < n; ++i) {
    a[i] = max(a[i] - minus, 0ll);
    if (k && a[i]) --a[i], --k;
  }
  for (auto v : a) cout << v << ' ';
}