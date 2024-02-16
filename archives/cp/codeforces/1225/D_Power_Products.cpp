#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  const int N = 1e5 + 1;
  map<vector<pair<int, int>>, ll> cnt;
  vector<int> lpf(N);
  iota(lpf.begin(), lpf.end(), 0);
  for (int i = 2; i < N; ++i) {
    if (lpf[i] == i) {
      for (int j = i; j < N; j += i) {
        lpf[j] = i;
      }
    }
  }
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    vector<pair<int, int>> f;
    while (x > 1) {
      int p = lpf[x];
      int e = 0;
      while (x % p == 0) {
        x /= p;
        ++e;
      }
      e %= k;
      if (e) f.emplace_back(p, e);
    }
    sort(f.begin(), f.end());
    vector<pair<int, int>> cf;
    for (auto [p, e] : f) cf.emplace_back(p, k - e);
    ans += cnt[cf];
    ++cnt[f];
  }
  cout << ans;
}