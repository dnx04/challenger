#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> lis;
  while (n--) {
    int x;
    cin >> x;
    auto itr = lower_bound(begin(lis), end(lis), x);
    if (itr != end(lis))
      *itr = x;
    else
      lis.push_back(x);
  }
  cout << lis.size();
}