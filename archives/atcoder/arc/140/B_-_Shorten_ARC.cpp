#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int sum = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      int l = i - 1, r = i + 1, len = 0;
      while (0 <= l && r < n) {
        if (s[l] == 'A' && s[r] == 'C')
          ++len, --l, ++r;
        else
          break;
      }
      if (len == 0) continue;
      sum += len;
      ++cnt;
    }
  }
  cout << min(sum, cnt * 2);
}