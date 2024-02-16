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
    map<pair<int, int>, int> cnt;
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'D')
        x++;
      else
        y++;
      int g = gcd(x, y);
      cout << cnt[{x / g, y / g}] + 1 << " \n"[i == n - 1];
      ++cnt[{x / g, y / g}];
    }
  }
}