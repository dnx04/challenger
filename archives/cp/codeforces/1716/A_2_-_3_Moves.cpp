#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "tools/prettyprint.hpp"
#endif

signed main() { 
  ios::sync_with_stdio(false), cin.tie(0); 
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    if(n == 1){
      cout << 2 << '\n';
    } else {
      cout << n / 3 + (n % 3 != 0) << '\n';
    }
  }
}