#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i += 2) {
      char a, b;
      cin >> a >> b;
      if (a == '0' && b == '0') cout << 'A';
      if (a == '0' && b == '1') cout << 'T';
      if (a == '1' && b == '0') cout << 'C';
      if (a == '1' && b == '1') cout << 'G';
    }
    cout << '\n';
  }
}