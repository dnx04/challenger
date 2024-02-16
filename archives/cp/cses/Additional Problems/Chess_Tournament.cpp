#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n;
  cin >> n;
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    pq.push({x, i});
  }
  vector<pair<int, int>> ans;
  while (!pq.empty()) {
    auto [rem, idx] = pq.top();
    pq.pop();
    vector<pair<int, int>> matched;
    while (!pq.empty() && rem) {
      auto [rem2, idx2] = pq.top();
      pq.pop();
      --rem, --rem2;
      ans.push_back({idx, idx2});
      if (rem2) matched.push_back({rem2, idx2});
    }
    if (rem) {
      cout << "IMPOSSIBLE";
      exit(0);
    }
    for (auto opp : matched) pq.push(opp);
  }
  cout << ans.size() << '\n';
  for (auto [u, v] : ans) cout << u + 1 << ' ' << v + 1 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}