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
    int a, b;
    cin >> a >> b;
    cout << min(a, b) << '\n';
  }
}