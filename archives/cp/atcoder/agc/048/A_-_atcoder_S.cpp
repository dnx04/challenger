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
    int len = s.length(), k = len;
    for (int i = 0; i < len; ++i) {
      if (s[i] != 'a') {
        k = i;
        break;
      }
    }
    if(s > "atcoder") cout << 0 << '\n';
    else if (k == len)
      cout << -1 << '\n';
    else if (s[k] <= 't')
      cout << k << '\n';
    else
      cout << k - 1 << '\n';
  }
}