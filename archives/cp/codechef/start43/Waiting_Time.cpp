#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() { 
  ios::sync_with_stdio(false), cin.tie(0); 
  int t;
  cin >> t;
  while(t--){
    int k, x;
    cin >> k >> x;
    cout << 7 * k - x << '\n';
  }
}