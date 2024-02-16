#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  const int MAX = 1e9 + 1;
  auto cal = [&](const vector<int> &a) {
    int n = a.size();
    vector<int> res;
    for (int i = 0; i < (1 << n); i++) {
      int sum = 0;
      for (int j = 0; j < n; j++) {
        if (i >> j & 1) {
          sum = min(sum + a[j], MAX);
        }
      }
      if (sum < MAX) res.push_back(sum);
    }
    sort(res.begin(), res.end());
    return res;
  };
  auto mp1 = cal(vector<int>(a.begin(), a.begin() + n / 2));
  auto mp2 = cal(vector<int>(a.begin() + n / 2, a.end()));
  ll ans = 0;
  for (auto i : mp1) {
    auto itr1 = lower_bound(mp2.begin(), mp2.end(), x - i);
    auto itr2 = upper_bound(mp2.begin(), mp2.end(), x - i);
    ans += itr2 - itr1;
  }
  cout << ans << '\n';
}