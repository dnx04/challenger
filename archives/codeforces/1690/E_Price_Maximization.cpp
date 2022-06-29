#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() { 
  ios::sync_with_stdio(false), cin.tie(0); 
  int tc;
  cin >> tc;
  while(tc--){
    int n, k;
    cin >> n >> k;
    int64_t ans = 0;
    vector<int> a(n);
    for(auto &v: a) cin >> v, ans += v / k, v %= k;
    sort(begin(a), end(a));
    for(int i = 0, j = n - 1; i < j; ++i, --j){
      while(a[i] + a[j] < k && i < j) ++i;
      if(i == j) break;
      ++ans;
    }
    cout << ans << '\n';
  }
}