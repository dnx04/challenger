#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define _GLIBCXX_ASSERTIONS
#endif

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() { 
  ios::sync_with_stdio(false), cin.tie(0); 
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i], a[i] ^= a[i - 1];
  while(q--){
    int l, r;
    cin >> l >> r;
    cout << (a[r] ^ a[l - 1]) << '\n';
  }
  
}