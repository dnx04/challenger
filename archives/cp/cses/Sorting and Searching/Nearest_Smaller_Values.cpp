#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  stack<pair<int, int>> st;
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    while (!st.empty() && st.top().first >= x) st.pop();
    if (!st.empty()) ans[i] = st.top().second;
    st.push({x, i + 1});
  }
  for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
}