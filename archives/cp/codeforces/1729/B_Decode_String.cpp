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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    vector<bool> cak(n);
    for(int i = n - 1; i >= 0; --i){
      if(s[i] == '0') cak[i - 2] = cak[i - 1] = true, i -= 2;
    }
    for (int i = 0; i < n; ++i) {
      if (!cak[i])
        ans += 'a' + s[i] - '0' - 1;
      else {
        stringstream ss;
        ss << s[i];
        ss << s[i + 1];
        int ord;
        ss >> ord;
        ans += 'a' + ord - 1;
        i += 2;
      }
    }
    cout << ans << '\n';
  }
}