#line 1 "Network_Breakdown.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 1 "algo/data-structure/dsu.hpp"
struct dsu {
 public:
  dsu(int n) : n(n), p(n, -1) {}

  int merge(int a, int b) {
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    int x = head(a), y = head(b);
    if (x == y) return x;
    if (-p[x] < -p[y]) swap(x, y);
    p[x] += p[y];
    p[y] = x;
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    return head(a) == head(b);
  }

  int head(int a) {
    assert(0 <= a && a < n);
    if (p[a] < 0) return a;
    return p[a] = head(p[a]);
  }

  int size(int a) {
    assert(0 <= a && a < n);
    return -p[head(a)];
  }

  vector<vector<int>> groups() {
    vector<int> tmp(n), sz(n);
    for (int i = 0; i < n; ++i) tmp[i] = head(i), ++sz[tmp[i]];
    vector<vector<int>> gr(n);
    for (int i = 0; i < n; ++i) gr[i].reserve(sz[i]);
    for (int i = 0; i < n; ++i) gr[tmp[i]].push_back(i);
    gr.erase(remove_if(begin(gr), end(gr),
                       [&](const vector<int>& v) { return v.empty(); }),
             end(gr));
    return gr;
  }

 private:
  int n;
  vector<int> p;
};
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
#line 10 "Network_Breakdown.cpp"

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(pair<int, int> x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(1ll * x.first * 998244353 + x.second + FIXED_RANDOM);
  }
};

void solve([[maybe_unused]] int ith) {
  int n, m, q;
  cin >> n >> m >> q;
  gp_hash_table<pair<int, int>, int, custom_hash> mp;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u > v) swap(u, v);
    mp[{u, v}] = 1;
  }
  vector<pair<int, int>> query(q);
  vector<int> ans(q);
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u > v) swap(u, v);
    query[i] = {u, v};
    mp[{u, v}] = 0;
  }
  dsu uf(n);
  for (auto [edge, exist] : mp) {
    if (exist) {
      uf.merge(edge.first, edge.second);
    }
  }
  int res = uf.groups().size();
  for (int i = q - 1; i >= 0; --i) {
    ans[i] = res;
    if (!uf.same(query[i].first, query[i].second)) {
      uf.merge(query[i].first, query[i].second);
      --res;
    }
  }
  for (auto x : ans) cout << x << ' ';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}