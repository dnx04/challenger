#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int q;
  cin >> q;
  multiset<ll> mts;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      ll x;
      cin >> x;
      mts.insert(x);
    } else if (t == 2) {
      ll x, k;
      cin >> x >> k;
      auto it = mts.upper_bound(x);
      while (k && it != mts.begin()) {
        k--;
        it--;
      }
      if (k == 0)
        cout << *it << '\n';
      else
        cout << "-1\n";
    } else if (t == 3) {
      ll x, k;
      cin >> x >> k;
      auto it = mts.lower_bound(x);
      while (--k && it != mts.end()) it++;
      if (it != mts.end())
        cout << *it << '\n';
      else
        cout << "-1\n";
    }
  }
}