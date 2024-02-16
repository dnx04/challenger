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
    int sum = 0;
    for (auto c : s) sum += (c == '0' ? -1 : 1);
    vector<tuple<int, int, int>> ops;
    auto apply = [&](int l, int r, int k) {
      ops.emplace_back(l, r, k);
      string res;
      res += s.substr(0, l);
      res += '0' + k;
      res += s.substr(r + 1);
      s = res;
      sum += (k == 1 ? 1 : -1);
    };
    bool opt = false;
    while (!opt) {
      opt = true;
      if (sum == 0) {
        apply(0, int(s.length()) - 1, 0);
        break;
      }
      for (int i = 0; i + 1 < (int)s.length(); ++i) {
        if (s[i] != s[i + 1]) {
          opt = false;
          if (sum < 0)
            apply(i, i + 1, 1);
          else
            apply(i, i + 1, 0);
          break;
        }
      }
    }
    cout << s.length() << ' ' << ops.size() << '\n';
    for (auto [l, r, k] : ops) {
      cout << l + 1 << ' ' << r + 1 << ' ' << k << '\n';
    }
  }
}