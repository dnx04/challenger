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
    vector<int> a(n);
    for(int i = 0; i < n; ++i) a[i] = i + 1;
    cout << n << '\n';
    for(int st = 0; st < n; ++st){
      for(auto v: a) cout << v << ' ';
      cout << '\n';
      if(st + 1 < n) swap(a[0], a[st + 1]);
    }
  }
}