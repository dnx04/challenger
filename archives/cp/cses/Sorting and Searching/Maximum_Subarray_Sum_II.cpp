#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  using ll = long long;
  int n, a, b;
  cin >> n >> a >> b;
  vector<ll> pre(n + 1);
  for (int i = 1; i <= n; ++i) cin >> pre[i], pre[i] += pre[i - 1];
  ll res = numeric_limits<ll>::min();
  multiset<ll> mts;
  for (int i = a; i <= n; ++i) {
    if (i > b) mts.erase(mts.find(pre[i - b - 1]));
    mts.insert(pre[i - a]);
    res = max(res, pre[i] - *begin(mts));
  }
  cout << res;
}