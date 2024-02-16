#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n;
  cin >> n;
  vector<int> pos_p(n + 1), pos_q(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    pos_p[x] = i;
  }
  for (int j = 1; j <= n; ++j) {
    int x;
    cin >> x;
    pos_q[x] = j;
  }
  vector<pair<int, int>> ord;
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      ord.emplace_back(pos_p[i], -pos_q[j]);
    }
  }
  sort(begin(ord), end(ord));
  multiset<int> s;
  for (const auto &[i, j] : ord) {
    s.insert(-j);
    auto it = s.lower_bound(-j);
    it++;

    if (it != s.end()) s.erase(it);
  }
  cout << s.size();
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}