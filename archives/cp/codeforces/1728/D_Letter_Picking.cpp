#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    int n = s.length();
    int l = 0, r = n - 1;
    for (; l <= r; l++, r--)
      if (s[l] != s[r]) break;
    for (; l <= r; l += 2)
      if (s[l] != s[l + 1]) break;
    if (l > r)
      cout << "Draw" << '\n';
    else
      cout << "Alice" << '\n';
  }
}