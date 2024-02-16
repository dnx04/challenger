#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  --a, --b, --c, --d;
  string s;
  cin >> s;
  auto bound = [&](int x) {
    int res = n;
    for (int i = x; i + 2 < n; ++i) {
      if (s[i + 1] == '#' && s[i + 2] == '#') {
        res = i;
        break;
      }
    }
    return res;
  };
  if (c <= bound(a) && d <= bound(b)) {
    if (c < d) {
      cout << "Yes";
      return;
    }
    for (int i = b - 1, cnt = 0; i <= min(d + 1, n - 1); ++i) {
      if (s[i] == '.') {
        if (++cnt >= 3) {
          cout << "Yes";
          return;
        }
      } else
        cnt = 0;
    }
  }
  cout << "No";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}