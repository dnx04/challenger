#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<int> p(n);
  for(auto &x: p) cin >> x;
  auto compress = [&](vector<int> &p) {
    vector<int> q = p;
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    for(auto &x: p) x = lower_bound(q.begin(), q.end(), x) - q.begin() + 1;
  };
  compress(p);
  int cnt = 0;
  for(int i = 0; i < n; ++i) cnt += (p[i] % 2 == i % 2);
  cout << cnt / 2;
}