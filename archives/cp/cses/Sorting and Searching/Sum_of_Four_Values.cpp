#line 1 "Sum_of_Four_Values.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 2 "algo/data-structure/pbds.hpp"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;  // find_by_order(), order_of_key()
template <typename TK>
using pbds_set = tree<TK, null_type, less<TK>, rb_tree_tag,
                      tree_order_statistics_node_update>;
template <typename TK, typename TV>
using pbds_map =
    tree<TK, TV, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;

#line 1 "algo/misc/chash.hpp"
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
#line 10 "Sum_of_Four_Values.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  gp_hash_table<int, pair<int, int>, custom_hash> mp;
  int n, sum;
  cin >> n >> sum;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  if (n >= 4) {
    for (int i = n; i >= 1; --i) {
      for (int j = i - 1; j >= 1; --j) {
        int targ = sum - a[i] - a[j];
        if (mp.find(targ) != end(mp)) {
          auto [x, y] = mp[targ];
          cout << i << ' ' << j << ' ' << x << ' ' << y;
          return 0;
        }
      }
      for (int j = i + 1; j <= n; ++j) mp[a[i] + a[j]] = {i, j};
    }
  }
  cout << "IMPOSSIBLE";
}
