#include <bits/extc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  int n;
  cin >> n;
  vector<int> a(n), b(n), mnd(n), mxd(n);
  vector<pair<int, int>> tot;
  for (int i = 0; i < n; ++i) cin >> a[i], tot.emplace_back(a[i], -(i + 1));
  for (int i = 0; i < n; ++i) cin >> b[i], tot.emplace_back(b[i], i + 1);
  for (int i = 0; i < n; ++i) {
    mnd[i] = *upper_bound(begin(b), end(b), a[i] - 1) - a[i];
  }
  stack<pair<int, int>> st;
  sort(begin(tot), end(tot));
  int sum = 0;
  for (auto v : tot) {
    if (v.second < 0)
      st.push(v), --sum;
    else {
      ++sum;
      if (sum == 0) {
        while (!st.empty()) {
          int idx = -st.top().second - 1;
          mxd[idx] = v.first - st.top().first;
          st.pop();
        }
      }
    }
  }
  for (auto v : mnd) cout << v << ' ';
  cout << '\n';
  for (auto v : mxd) cout << v << ' ';
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}