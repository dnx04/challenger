#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    set<int> a({10, 20, 30, 40, 50, 60, 70, 80, 90});
    int x, y;
    cin >> x >> y;
    if(x > y) swap(x, y);
    int ans = 0;
    for(int i = x; i <= y; ++i){
      if(a.count(i) && i + 1 <= y) ++ans;
    }
    cout << ans << '\n';
  }
}