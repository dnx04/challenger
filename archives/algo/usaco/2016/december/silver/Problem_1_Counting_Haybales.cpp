#include <bits/extc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sort(begin(a), end(a));
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << upper_bound(begin(a), end(a), r) - lower_bound(begin(a), end(a), l)
         << '\n';
  }
}