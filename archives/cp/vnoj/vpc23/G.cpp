#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

auto segment_union = [](vector<pair<int, int>> &segs) {
  vector<pair<int, int>> res, lr;
  for (auto &[u, v] : segs) {
    lr.emplace_back(u, 0);
    lr.emplace_back(v + 1, 1);
  }
  stack<int> st;
  sort(lr.begin(), lr.end());
  for (auto &[x, t] : lr) {
    if (t == 0) {
      st.push(x);
    } else {
      if (st.size() == 1) {
        res.emplace_back(st.top(), x - 1);
      }
      st.pop();
    }
  }
  return res;
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, X, Y;
  cin >> n >> X >> Y;
  vector<pair<int, int>> sx, sy;
  for (int i = 0; i < n; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    sx.emplace_back(max(x - w, 1), min(x + w, X));
    sy.emplace_back(max(y - w, 1), min(y + w, Y));
  }
  auto ux = segment_union(sx);
  auto uy = segment_union(sy);
  ll uxl, uyl;
  uxl = uyl = 0;
  for (auto &[u, v] : ux) {
    uxl += v - u + 1;
  }
  for (auto &[u, v] : uy) {
    uyl += v - u + 1;
  }
  cout << 1ll * X * Y - 1ll * (X - uxl) * (Y - uyl) << '\n';
}