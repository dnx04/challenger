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
    int x, n;
    cin >> x >> n;
    cout << x / 10 * n << '\n';
  }
}