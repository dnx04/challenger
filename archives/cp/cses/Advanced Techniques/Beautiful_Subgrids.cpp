#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  const int sz = 64;
  int n;
  cin >> n;
  vector<uint64_t> board[n];
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; j += sz) {
      board[i].push_back(bitset<sz>(s.substr(j, sz)).to_ullong());
    }
  }
  uint64_t ans = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = l + 1; r < n; ++r) {
      int cnt = 0;
      for (int i = 0; i < (n + sz - 1) / sz; ++i) {
        cnt += __builtin_popcountll(board[l][i] & board[r][i]);
      }
      ans += cnt * (cnt - 1) / 2;
    }
  }
  cout << ans;
}