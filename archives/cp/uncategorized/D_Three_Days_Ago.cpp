#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  string s;
  cin >> s;
  int n = s.length();
  vector<vector<bool>> cntxor(10, vector<bool>(n + 1, false));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 10; ++j) {
      cntxor[j][i] = cntxor[j][i - 1] ^ (s[i - 1] - '0' == j);
    }
  }
  vector<int> binexpr(n + 1);
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < 10; ++j) {
      binexpr[i] += cntxor[j][i] * (1 << j);
    }
  }
  vector<int> cnt(1 << 10, 0);
  for (int i = 0; i <= n; ++i) {
    ++cnt[binexpr[i]];
  }
  ll ans = 0;
  for (int i = 0; i < (1 << 10); ++i) {
    ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
  }
  cout << ans << '\n';
}