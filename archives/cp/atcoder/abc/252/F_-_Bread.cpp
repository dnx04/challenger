#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  int64_t l, sum = 0;
  cin >> n >> l;
  priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sum += x;
    pq.push(x);
  }
  if (sum < l) pq.push(l - sum);
  int64_t ans = 0;
  while (pq.size() > 1) {
    int64_t left = pq.top();
    pq.pop();
    int64_t right = pq.top();
    pq.pop();
    ans += left + right;
    pq.push(left + right);
  }
  cout << ans;
}