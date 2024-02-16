#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (auto &a : x) cin >> a;
    for (auto &a : y) cin >> a;
    vector<int> diff(n);
    priority_queue<int> neg;
    priority_queue<int, vector<int>, greater<int>> pos;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      diff[i] = y[i] - x[i];
      if (diff[i] == 0)
        ++ans;
      else if (diff[i] < 0)
        neg.push(diff[i]);
      else
        pos.push(diff[i]);
    }
    if (ans % 2 == 1) pos.push(0);
    ans /= 2;
    while (!pos.empty()) {
      int cnt = 1;
      int sum = pos.top();
      pos.pop();
      if (!neg.empty() && neg.top() + sum >= 0) {
        sum += neg.top();
        neg.pop();
        ++cnt;
      } else if (!pos.empty()) {
        sum += pos.top();
        pos.pop();
        ++cnt;
      }
      if (cnt >= 2) ++ans;
    }
    cout << ans << '\n';
  }
}