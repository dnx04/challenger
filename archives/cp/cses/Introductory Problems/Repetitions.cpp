#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  string s;
  cin >> s;
  int cnt = 1, mx = 1;
  for (int i = 0; i < (int)s.size() - 1; ++i) {
    if (s[i] == s[i + 1])
      ++cnt;
    else
      cnt = 1;
    mx = max(mx, cnt);
  }
  cout << max(mx, cnt);  // in case of s[n - 1] == s[n]
}