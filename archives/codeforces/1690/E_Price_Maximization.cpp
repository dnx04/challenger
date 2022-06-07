#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    vector<int> cnt(k);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ans += x;
      ++cnt[x % k];
    }
    int minus = 0;
    set<int> rem;
    for (int i = 0; i < k; ++i)
      if (cnt[i]) rem.insert(i);

    for (int d = 0; d < k; ++d) {
      set<int> del;
      for (auto ele : rem) {
        int targ = (k + d - ele) % k;
        if (!del.count(ele) && !del.count(targ)) {
          int pick = min(cnt[ele], cnt[targ]);
          if (ele == targ) pick /= 2;
          minus += d * pick;
          cnt[ele] -= pick;
          cnt[targ] -= pick;
          if (cnt[ele] == 0) del.insert(ele);
          if (cnt[targ] == 0) del.insert(targ);
        }
      }
      for (auto ele : del) rem.erase(ele);
    }
    cout << (ans - minus) / k << '\n';
  }
}