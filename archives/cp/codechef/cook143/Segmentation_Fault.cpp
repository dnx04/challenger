#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> s(n + 1), l(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> l[i] >> r[i];
      ++s[l[i]], --s[r[i] + 1];
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
      s[i] += s[i - 1];
      if (s[i] == n - 1 && (i < l[i] || r[i] < i)) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto ele : ans) cout << ele << '\n';
  }
}