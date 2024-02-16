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
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    int cnt = (a[0] > 0) + (a[1] > 0) + (a[2] > 0);
    int ans = cnt;
    vector<pair<int, int>> mv({{0, 1}, {0, 2}, {1, 2}});
    do {
      int tmp = cnt;
      vector<int> b(a);
      for (auto [u, v] : mv) {
        if (b[u] > 1 && b[v] > 1) ++tmp, --b[u], --b[v];
      }
      ans = max(ans, tmp);
    } while (next_permutation(mv.begin(), mv.end()));
    cout << ans << '\n';
  }
}