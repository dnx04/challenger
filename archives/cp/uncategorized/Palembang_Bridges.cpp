#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int k, n;
  cin >> k >> n;
  if (k == 1) {
    vector<int> nums;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      char a, b;
      int x, y;
      cin >> a >> x >> b >> y;
      if (a == b)
        ans += abs(x - y);
      else
        nums.push_back(x), nums.push_back(y);
    }
    sort(begin(nums), end(nums));
    int med = nums.size() / 2;
    cout << nums << '\n';
    for (auto &x : nums) ans += abs(x - nums[med]);
    cout << ans;
  }
}