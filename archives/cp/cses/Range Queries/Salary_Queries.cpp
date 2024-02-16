#line 1 "Salary_Queries.cpp"
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
#line 9 "Salary_Queries.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  pbds_set<pair<int, int>> oset;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    oset.insert({p[i], i});
  }

  while (q--) {
    char typ;
    cin >> typ;
    if (typ == '!') {
      int i, x;
      cin >> i >> x;
      i--;
      oset.erase({p[i], i});
      p[i] = x;
      oset.insert({x, i});
    } else {
      int a, b;
      cin >> a >> b;
      cout << oset.order_of_key({b, n}) - oset.order_of_key({a - 1, n}) << '\n';
    }
  }
}
