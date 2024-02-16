#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

const int N = 41;
int n, xg, yg, x[N], y[N];

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> xg >> yg;
  for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  // meet in the middle
  vector<vector<pair<int,int>>> v1(N / 2 + 1), v2(N / 2 + 1);
  int sz1 = (n + 1) / 2, sz2 = n - sz1;

  for(int msk = 0; msk < (1 << sz1); ++msk){
    int sx = 0, sy = 0, step = 0;
    for(int i = 0; i < sz1; ++i){
      if((msk >> i) & 1) sx += x[i], sy += y[i], ++step;
    }
    v1[step].push_back({sx, sy});
  }

  for (int msk = 0; msk < (1 << sz2); ++msk) {
    int sx = 0, sy = 0, step = 0;
    for (int i = 0; i < sz2; ++i) {
      if ((msk >> i) & 1) sx += x[sz1 + i], sy += y[sz1 + i], ++step;
    }
    v2[step].push_back({xg - sx, yg - sy});
  }
  vector<int64_t> ans(N);
  for(int i = 0; i <= sz1; ++i) sort(begin(v1[i]), end(v1[i]));
  for(int i = 0; i <= sz2; ++i) sort(begin(v2[i]), end(v2[i]));
  for(int i = 0; i <= sz1; ++i){
    for(auto ele: v1[i]){
      for(int j = 0; j <= sz2; ++j){
        auto itr1 = lower_bound(begin(v2[j]), end(v2[j]), ele);
        auto itr2 = upper_bound(begin(v2[j]), end(v2[j]), ele);
        ans[i + j] += itr2 - itr1;
      }
    }
  }
  for(int i = 1; i <= n; ++i) cout << ans[i] << '\n';
}