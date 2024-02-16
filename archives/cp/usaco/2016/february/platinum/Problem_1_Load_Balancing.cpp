#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  const int N = 1 << 17;
  vector<vector<int>> st(2, vector<int>(2 * N));
  auto update = [&](vector<int> &s, int x, int v) {
    x += N;
    s[x] += v;
    for (x = x >> 1; x; x = x >> 1) s[x] = s[2 * x] + s[2 * x + 1];
  };
  auto query = [&](auto query, int x, int l0, int r0, int l1, int r1) {
    if (x > N) {
      (l0 < r0 ? l0 : r0) += st[0][x];
      (l1 < r1 ? l1 : r1) += st[1][x];
      return max(max(l0, r0), max(l1, r1));
    }
    int c0 = (x << 1), c1 = (x << 1) | 1;
    if (max(l0 + st[0][c0], l1 + st[1][c0]) <
        max(r0 + st[0][c1], r1 + st[1][c1])) {
      return query(query, c1, l0 + st[0][c0], r0, l1 + st[1][c0], r1);
    } else {
      return query(query, c0, l0, r0 + st[0][c1], l1, r1 + st[1][c1]);
    }
  };
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &[x, y] : a) cin >> x >> y;
  sort(a.begin(), a.end());
  int lx = a[0].first, xp = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i].first != lx) lx = a[i].first, ++xp;
    a[i].first = xp;
  }
  sort(begin(a), end(a), [](pair<int, int> a, pair<int, int> b) {
    return make_pair(a.second, a.first) < make_pair(b.second, b.first);
  });
  for (int i = 0; i < n; ++i) update(st[0], a[i].first, 1);
  int res = N;
  for (int i = 0; i < n;) {
    int sz = 0;
    while (i + sz < n && a[i + sz].second == a[i].second) {
      update(st[0], a[i + sz].first, -1);
      update(st[1], a[i + sz].first, 1);
      ++sz;
    }
    res = min(res, query(query, 1, 0, 0, 0, 0));
    i += sz;
  }
  cout << res;
}