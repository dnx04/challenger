#include "bits/stdc++.h"

#ifdef LOCAL
#include "tools/prettyprint.hpp"
#endif

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);

  int n;
  cin >> n;
  vector<int> p(n), q(n);
  for (auto &x : p) cin >> x, --x;
  for (auto &x : q) cin >> x, --x;

  vector<pair<int, int>> pid;
  for (int i = 0; i < n; ++i) {
    pid.push_back({p[i], q[i]});
  }
  sort(begin(pid), end(pid));
  for (int i = 0; i < n - 1; ++i) {
    auto [xa, ya] = pid[i];
    auto [xb, yb] = pid[i + 1];
    if ((xa == xb && ya != yb) || (xa != xb && ya == yb)) {
      return cout << "NO", 0;
    }
  }
  pid.resize(unique(begin(pid), end(pid)) - begin(pid));
  // step 2
  vector<int> t(n), m(n);
  int c = pid.size() + 1;
  for (int i = 0; i < (int)pid.size(); ++i) {
    auto [x, y] = pid[i];
    t[x] = i + 1, m[y] = c - t[x];
  }

  // step 3
  const int MAX = 1e9;
  for (int i = 0; i < n; ++i) {
    if (!t[i]) t[i] = MAX - i;
    if (!m[i]) m[i] = MAX - i;
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) cout << t[i] << " \n"[i == n - 1];
  for (int i = 0; i < n; ++i) cout << m[i] << " \n"[i == n - 1];
}