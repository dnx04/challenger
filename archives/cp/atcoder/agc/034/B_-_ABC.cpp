#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  string s;
  cin >> s;
  int n = s.length();
  ll ans = 0, cnt = 0;
  string t;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'B') {
      if (i + 1 < n && s[i + 1] == 'C')
        t += 'D', ++i;
      else
        t += s[i];
    } else {
      t += s[i];
    }
  }
  for (auto c : t) {
    if (c == 'A') {
      ++cnt;
    } else if (c == 'D') {
      ans += cnt;
    } else {
      cnt = 0;
    }
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}