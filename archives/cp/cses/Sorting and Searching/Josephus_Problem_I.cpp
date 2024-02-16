#line 1 "Josephus_Problem_I.cpp"
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#line 1 "algo/data-structure/pbds.hpp"
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#line 8 "Josephus_Problem_I.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, k;
  cin >> n;
  k = 1;
  ordered_set<int> s;
  for (int i = 1; i <= n; ++i) s.insert(i);
  int idx = k % n;
  while (n--) {
    auto y = s.find_by_order(idx);
    cout << *y << ' ';
    s.erase(y);
    if (n) idx = (idx + k) % n;
  }
}
