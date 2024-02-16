#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n;
  cin >> n;
  vector<int> c(n);
  for (auto &x : c) cin >> x;
  int sum = accumulate(begin(c), end(c), 0);
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    if (c[i] > sum - c[i]) {
      ans = i + 1;
      break;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}