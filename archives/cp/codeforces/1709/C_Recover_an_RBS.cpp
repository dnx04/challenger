#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;

void solve(int ith) {
  string bs;
  cin >> bs;
  int wh = 0, cnt = 0;
  for (auto c : bs) {
    if (c == '(') ++cnt;
    if (c == ')') --cnt;
    if (c == '?') ++wh;
    if (cnt + wh == 1) cnt = 1, wh = 0;
  }
  if (abs(cnt) == wh)
    cout << "YES\n";
  else
    cout << "NO\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}