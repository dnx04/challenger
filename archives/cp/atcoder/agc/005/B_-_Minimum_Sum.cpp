#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), l(n), r(n);
  iota(begin(l), end(l), 0);
  iota(begin(r), end(r), 0);
  for (auto &v : a) cin >> v;

  stack<pair<int, int>> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && st.top().second > a[i]) st.pop();
    if (!st.empty())
      l[i] = st.top().first + 1;
    else
      l[i] = 0;
    st.push({i, a[i]});
  }
  while (!st.empty()) st.pop();
  for (int i = n - 1; i >= 0; --i) {
    while (!st.empty() && st.top().second > a[i]) st.pop();
    if (!st.empty())
      r[i] = st.top().first - 1;
    else
      r[i] = n - 1;
    st.push({i, a[i]});
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) ans += 1ll * a[i] * (r[i] - i + 1) * (i - l[i] + 1);
  cout << ans;
}