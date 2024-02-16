#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n;
  cin >> n;
  deque<int> dq;
  vector<int> srt(n);
  for (auto &v : srt) cin >> v;
  sort(begin(srt), end(srt));
  for (auto v : srt) dq.push_back(v);
  int ans = 0;
  while (dq.size() > 1) {
    auto pick = dq.back();
    dq.pop_back();
    if (pick % dq.front()) {
      dq.push_front(pick % dq.front());
    }
    ++ans;
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}