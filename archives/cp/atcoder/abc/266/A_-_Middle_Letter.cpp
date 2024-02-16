#include <bits/extc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  string s;
  cin >> s;
  cout << s[s.length() >> 1];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}