#include <bits/extc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() { 
  ios::sync_with_stdio(false), cin.tie(0); 
  long long n;
  cin >> n;
  long long lo = 1, hi = 1e12, ans = 0;
  while(lo <= hi){
    long long mid = (lo + hi) >> 1, cnt = 0;
    for(int i = 1; i <= n; ++i) cnt += min(n, mid / i);
    if(cnt >= n * n / 2 + 1) ans = mid, hi = mid - 1;
    else lo = mid + 1;
  }
  cout << ans;
}