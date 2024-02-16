#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n;
  ll k;
  cin >> n >> k;
  deque<int> dq;
  for (int i = 1; i <= n; ++i) dq.push_back(i);
  vector<int> ans(n + 1);
  for (int i = n - 1, j = 1; i >= 0; --i, ++j) {
    if (i <= k) {
      ans[j] = dq.back();
      dq.pop_back();
      k -= i;
    } else {
      ans[j] = dq.front();
      dq.pop_front();
    }
  }
  for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}