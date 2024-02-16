#include <bits/extc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &v : a) cin >> v;
  for (auto &v : b) cin >> v, v = ~v;
  int ans = 0;
  for (int st = 29; st >= 0; --st) {
    vector<int> v1, v2;
    for (auto v : a) v1.push_back(v & (ans ^ (1 << st)));
    for (auto v : b) v2.push_back(v & (ans ^ (1 << st)));
    sort(begin(v1), end(v1));
    sort(begin(v2), end(v2));
    if (v1 == v2) ans += (1 << st);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}