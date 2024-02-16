#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  stack<pair<int, int>> st;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int start = i;
    while (!st.empty() && st.top().first > a[i]) {
      auto cur = st.top();
      st.pop();
      start = cur.second;
      ans = max(ans, 1ll * (i - cur.second) * cur.first);
    }
    st.push({a[i], start});
  }
  while (!st.empty()) {
    auto cur = st.top();
    st.pop();
    ans = max(ans, 1ll * (n - cur.second) * cur.first);
  }
  cout << ans;
}