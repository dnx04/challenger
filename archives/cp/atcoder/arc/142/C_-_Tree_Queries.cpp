#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  int n;
  cin >> n;
  vector<int> d1u(n + 1), d2u(n + 1);
  set<int> d2f1, d2f2;  // d <= 2 from 1 and 2
  auto ask = [&](int u, int v) { cout << "? " << u << ' ' << v << endl; };
  auto ans = [&](int d) { cout << "! " << d << endl; };

  for (int i = 3; i <= n; ++i) {  // 2 * (n - 2) queries
    ask(1, i);
    cin >> d1u[i];
    if (d1u[i] <= 2) d2f1.insert(i);
    ask(2, i);
    cin >> d2u[i];
    if (d2u[i] <= 2) d2f2.insert(i);
  }
  int maybe_ans = n;
  for (int i = 3; i <= n; ++i) maybe_ans = min(maybe_ans, d1u[i] + d2u[i]);
  if (maybe_ans > 3 || maybe_ans == 2) {
    ans(maybe_ans);
  } else {
    vector<int> pick;
    for (auto ele : d2f1) {
      if (d2f2.count(ele)) {
        pick.push_back(ele);
      }
    }
    if (pick.size() == 2) {
      ask(pick[0], pick[1]);
      int x;
      cin >> x;
      if (x == 3 || x == 2) // ? I missed x = 2
        ans(1);
      else
        ans(3);
    } else {
      ans(1);
    }
  }
}