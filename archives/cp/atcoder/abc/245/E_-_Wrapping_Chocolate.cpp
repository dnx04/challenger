#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), c(m), d(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  for (auto &x : c) cin >> x;
  for (auto &x : d) cin >> x;
  multiset<int> mts;
  vector<tuple<int, int, int>> sz;
  for (int i = 0; i < n; ++i) sz.push_back({a[i], b[i], 1});
  for (int i = 0; i < m; ++i) sz.push_back({c[i], d[i], 0});
  sort(sz.begin(), sz.end(), [&](auto &x, auto &y) {
    return get<0>(x) > get<0>(y) ||
           (get<0>(x) == get<0>(y) && get<2>(x) < get<2>(y));
  });
  bool ok = true;
  for (int i = 0; i < n + m; ++i) {
    // cerr << sz[i] << '\n';
    if (get<2>(sz[i]) == 0) {
      mts.insert(get<1>(sz[i]));
    } else {
      auto it = mts.lower_bound(get<1>(sz[i]));
      if (it == mts.end()) {
        ok = false;
        break;
      }
      mts.erase(it);
    }
  }
  cout << (ok ? "Yes" : "No");
}