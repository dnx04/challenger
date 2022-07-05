#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx[] = {1, 2, 1, 2, -1, -2, -1, -2};
    int dy[] = {2, 1, -2, -1, 2, 1, -2, -1};
    auto valid = [](int x, int y) {
      return (1 <= x && x <= 8 && 1 <= y && y <= 8);
    };
    bool ok = false;
    for (int i = 1; i <= 8; ++i) {
      for (int j = 1; j <= 8; ++j) {
        int strike = 0;
        for (int k = 0; k < 8; ++k) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (valid(nx, ny)) {
            if (nx == x1 && ny == y1) ++strike;
            if (nx == x2 && ny == y2) ++strike;
          }
        }
        if (strike == 2) ok = true;
      }
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}