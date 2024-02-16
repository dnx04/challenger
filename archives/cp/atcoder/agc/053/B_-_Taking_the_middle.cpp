#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (auto &v : a) cin >> v;
  int64_t sum = accumulate(begin(a), end(a), 0ll);
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = n - 1, j = n; i >= 0; --i, ++j) {
    pq.push(a[i]);
    pq.push(a[j]);
    sum -= pq.top();
    pq.pop();
  }
  cout << sum;
}