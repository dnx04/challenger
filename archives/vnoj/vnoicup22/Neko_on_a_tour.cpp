#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<pair<int, int>, int>> p;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b;
    p.push_back({{a, b}, i});
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < n; ++i) {
    if (p[i].first.second < p[n - 1].first.first) {
      cout << "YES\n" << p[i].second << ' ' << p[n - 1].second << '\n';
      return 0;
    }
  }
  cout << "NO\n";
}