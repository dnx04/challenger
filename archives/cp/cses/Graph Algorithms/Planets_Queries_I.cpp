#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  const int k = 30;
  vector<vector<int>> up(k, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    up[0][i] = x - 1;
  }
  for (int i = 1; i < k; ++i) {
    for (int j = 0; j < n; ++j) {
      up[i][j] = up[i - 1][up[i - 1][j]];
    }
  }
  auto lift = [&](int u, int step) {
    for (int i = k - 1; i >= 0; --i) {
      if ((step >> i) & 1) u = up[i][u];
    }
    return u;
  };
  while (q--) {
    int x, k;
    cin >> x >> k;
    cout << lift(x - 1, k) + 1 << '\n';
  }
}