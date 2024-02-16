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
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) pos[s[i] - 'a'].push_back(i);
    vector<int> mv;
    mv.push_back(1);
    if (s[0] <= s.back()) {
      for (int i = s[0] - 'a'; i <= s.back() - 'a'; ++i) {
        for (auto v : pos[i]) {
          if (v != 0 && v != n - 1) mv.push_back(v + 1);
        }
      }
    } else {
      for (int i = s[0] - 'a'; i >= s.back() - 'a'; --i) {
        for (auto v : pos[i]) {
          if (v != 0 && v != n - 1) mv.push_back(v + 1);
        }
      }
    }
    mv.push_back(n);
    cout << abs(s[0] - s.back()) << ' ' << mv.size() << '\n';
    for (auto v : mv) cout << v << ' ';
    cout << '\n';
  }
}