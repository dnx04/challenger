#include <bits/extc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  int n, m, sx, sy, d;
  cin >> n >> m >> sx >> sy >> d;
  bool b1 = abs(sx - 1) <= d && abs(sy - 1) <= d;
  bool b2 = abs(sx - n) <= d && abs(sy - m) <= d;
  bool b3 = abs(sx - 1) <= d && abs(sx - n) <= d;
  bool b4 = abs(sy - 1) <= d && abs(sy - m) <= d;
  if(b1 || b2 || b3 || b4) cout << "-1\n";
  else cout << n + m - 2 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}