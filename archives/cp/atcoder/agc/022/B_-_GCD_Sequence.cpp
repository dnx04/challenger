#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  if (n == 3)
    cout << "2 5 63";
  else {
    vector<int> even({2, 10, 3, 9, 4, 8, 6, 12});
    vector<int> odd({6, 2, 10, 3, 9, 4, 8, 12});
    if (n % 2 == 0) {
      for (int i = 0; i < n; ++i) cout << even[i % 8] + 12 * (i / 8) << ' ';
    } else {
      for (int i = 0; i < n; ++i) cout << odd[i % 8] + 12 * (i / 8) << ' ';
    }
  }
}