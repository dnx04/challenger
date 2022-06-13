#include <bits/extc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() { 
  ios::sync_with_stdio(false), cin.tie(0); 
  int n;
  cin >> n;
  set<int> s;
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    s.insert(x);
  }
  cout << s.size();
}