#include "bits/extc++.h"

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#ifdef DEBUG
#include "tools/prettyprint.hpp"
#endif

signed main() { 
  ios::sync_with_stdio(false), cin.tie(0); 
  using ll = long long;
  const ll LIM = 1e18;
  ll n;
  int k;
  cin >> n >> k;
  vector<ll> p(k);
  for(int i = 0; i < k; ++i) cin >> p[i];
  ll ans = 0;
  for(int mask = 1; mask < (1 << k); ++mask) {
    ll prod = 1;
    for(int i = 0; i < k; ++i) {
      if(mask & (1 << i)) {
        if(prod <= LIM / p[i]){
          prod *= p[i];
        } else {
          prod = LIM + 1;
          break;
        }
      }
    }
    if(__builtin_popcount(mask) % 2 == 0) ans -= n / prod;
    else ans += n / prod;
  }
  cout << ans;
}