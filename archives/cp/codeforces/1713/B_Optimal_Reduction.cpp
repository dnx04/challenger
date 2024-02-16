#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "tools/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> p(n);
    priority_queue<int> pq;
    int mx = 0, l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
      pq.push(p[i]);
      if (p[i] > mx) {
        mx = p[i];
        l = i, r = i;
      }
    }
    while (!pq.empty()) {
      int x = pq.top();
      pq.pop();
      if (l >= 0 && p[l] == x) {
        if (l == r) ++r;
        --l;
      } else if (r < n && p[r] == x) {
        ++r;
      } else {
        break;
      }
    }

    if (pq.empty())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}