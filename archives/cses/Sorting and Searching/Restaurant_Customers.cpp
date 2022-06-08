#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> sched;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    sched.push_back({a, 1});
    sched.push_back({b, -1});
  }
  sort(begin(sched), end(sched));
  int ans = 0, cnt = 0;
  for (auto &event : sched) {
    cnt += event.second;
    ans = max(ans, cnt);
  }
  cout << ans;
}