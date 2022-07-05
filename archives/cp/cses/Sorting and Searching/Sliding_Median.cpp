#include "bits/extc++.h"

using namespace std;
using namespace __gnu_pbds;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

int main() {
  int n, k;
  cin >> n >> k;
  ordered_set oset;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    oset.insert({a[i], i});
    if (i >= k) {
      oset.erase(oset.lower_bound({a[i - k], 0}));
    }
    if (i >= k - 1) {
      cout << (*oset.find_by_order((k - 1) / 2)).first << ' ';
    }
  }
}