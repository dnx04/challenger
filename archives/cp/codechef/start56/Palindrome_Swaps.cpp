#line 1 "Palindrome_Swaps.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 1 "algo/data-structure/fenwick.hpp"
template <typename T>
struct fenwick_tree {
  fenwick_tree(int _n) : n(_n), f(_n + 1) {}

  // a[u] += val
  void add(int u, T val) {
    assert(0 <= u && u < n);
    ++u;
    while (u <= n) {
      f[u] += val;
      u += u & -u;
    }
  }

  // return the sum of [0, u)
  T sum(int u) const {
    assert(0 <= u && u <= n);
    T res = 0;
    while (u) {
      res += f[u];
      u -= u & -u;
    }
    return res;
  }

  // return the sum of [l, r)
  T sum(int l, int r) const {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return 0;
    return sum(r) - sum(l);
  }

  void reset() { fill(f.begin(), f.end(), T(0)); }

  int n;
  vector<T> f;
};
#line 9 "Palindrome_Swaps.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &x : s) cin >> x;
    ll ans = 0;
    for (int i = 0; i < m / 2; ++i) {
      vector<vector<int>> cnt(2, vector<int>(26));
      for (int j = 0; j < n; ++j) {
        ++cnt[0][s[j][i] - 'a'];
        ++cnt[1][s[j][m - i - 1] - 'a'];
      }
      bool ok = true;
      for (int j = 0; j < 26; ++j)
        if (cnt[0][j] != cnt[1][j]) ok = false;
      if (!ok) {
        ans = -1;
        break;
      } else {
        fenwick_tree<int> ft(n + 1);
        vector<vector<int>> pos1(26), pos2(26);
        vector<int> c(n);
        for (int j = 0; j < n; ++j) {
          pos1[s[j][i] - 'a'].push_back(j);
          pos2[s[j][m - i - 1] - 'a'].push_back(j);
        }
        for (int j = 0; j < 26; ++j) {
          for (int k = 0; k < (int)pos1[j].size(); ++k) {
            c[pos1[j][k]] = pos2[j][k];
          }
        }
        for (int j = 0; j < n; ++j) {
          ans += ft.sum(c[j] + 1, n + 1), ft.add(c[j], 1);
        }
      }
    }
    cout << ans << '\n';
  }
}
