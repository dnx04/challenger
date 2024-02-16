#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;

void solve(int ith) {
  int k, a[3];
  cin >> k >> a[0] >> a[1] >> a[2];
  for (int i = 0; i < 3; ++i) {
    if (a[i] == i + 1) {
      cout << "NO\n";
      return;
    }
  }
  cout << (a[k - 1] != k && a[k - 1] != 0 ? "YES\n" : "NO\n");
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}