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
    int p, q;
    cin >> p >> q;
    if((p + q) % 4 < 2) cout << "Alice\n";
    else cout << "Bob\n";
  }
}