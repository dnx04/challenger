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
    int n;
    cin >> n;
    vector<int64_t> mex(n), max_occ(n + 2), min_occ(n + 2);
    for (auto &ele : mex) {
      cin >> ele;
      max_occ[0] += n - ele + 1;
      max_occ[ele] -= n - ele + 1;
      max_occ[ele + 1] += n - ele;
    }
    for (int i = 1; i < n; ++i) max_occ[i] += max_occ[i - 1];
    for (auto ele : mex) {
      min_occ[0] += 1;
      min_occ[ele] -= 1;
    }
    for (int i = 1; i < n; ++i) min_occ[i] += min_occ[i - 1];
    for (int i = 0; i < n; ++i) cout << min_occ[i] << ' ' << max_occ[i] << '\n';
  }
}