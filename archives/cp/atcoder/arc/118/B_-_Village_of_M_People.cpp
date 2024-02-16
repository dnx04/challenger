#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int k, n, m;
  cin >> k >> n >> m;
  vector<ll> a(k), b(k);
  vector<pair<ll, int>> diff(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
    b[i] = a[i] * m / n;
    diff[i] = {b[i] * n - a[i] * m, i};
  }
  sort(begin(diff), end(diff));
  ll add = m - accumulate(begin(b), end(b), 0ll);
  for (int i = 0; i < k && add > 0; ++i) {
    --add;
    ++b[diff[i].second];
  }
  for(auto x : b) cout << x << ' ';
}