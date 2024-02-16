#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<pair<int, int>> t;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      t.push_back({x, 0});
    }
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      t.push_back({x, 1});
    }
    sort(begin(t), end(t));
    deque<int> dq;
    for (auto ele : t) {
      if (ele.second == 0)
        dq.push_back(ele.first);
      else {
        cout << ele.first - dq.front() << ' ';
        dq.pop_front();
        if (!dq.empty()) {
          auto nxt = dq.front();
          dq.pop_front();
          dq.push_front(max(nxt, ele.first));
        }
      }
    }
    cout << '\n';
  }
}