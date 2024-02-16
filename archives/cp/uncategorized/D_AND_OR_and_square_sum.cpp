#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<vector<bool>> bit(20, vector<bool>(n, false));
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    for (int j = 0; j < 20; ++j) {
      bit[j][i] = x >> j & 1;
    }
  }
  for(auto &v: bit) sort(v.begin(), v.end());
  ll ans = 0;
  for(int i = 0; i < n; ++i){
    ll num = 0;
    for(int j = 0; j < 20; ++j){
      num += bit[j][i] * (1 << j);
    }
    ans += num * num;
  }
  cout << ans << '\n';
}