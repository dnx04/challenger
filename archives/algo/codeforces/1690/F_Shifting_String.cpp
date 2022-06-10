#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) cin >> p[i];
    vector<bool> chk(n + 1);
    vector<int> cycle;
    for (int i = 1; i <= n; ++i) {
      if (!chk[i]) {
        string str;
        int ptr = i;
        do {
          chk[ptr] = true;
          str += s[ptr - 1];
          ptr = p[ptr];
        } while (!chk[ptr]);

        if (str.length() == 1)
          cycle.push_back(1);
        else {
          for (int d = 1;; ++d) {
            string new_str = str;
            rotate(new_str.rbegin(), new_str.rbegin() + d, new_str.rend());
            if (str == new_str) {
              cycle.push_back(d);
              break;
            }
          }
        }
      }
    }
    long long ans = 1;
    for (auto ele : cycle) {
      ans = ans * ele / gcd(ans, ele);
    }
    cout << ans << '\n';
  }
}