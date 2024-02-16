#include <bits/extc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int x, n;
  cin >> x >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    pq.push(x);
  }
  long long ans = 0;
  while (pq.size() > 1) {
    int left = pq.top();
    pq.pop();
    int right = pq.top();
    pq.pop();
    pq.push(left + right);
    ans += left + right;
  }
  cout << ans;
}