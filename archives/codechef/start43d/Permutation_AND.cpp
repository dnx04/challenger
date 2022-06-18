#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << "1\n1\n";
    } else if (n & 1) {
      cout << -1 << '\n';
    } else {
      vector<pair<int,int>> ans;
      vector<bool> chk(n + 1);
      for(int i = n, p = (1 << 20); i >= 1; --i){
        if(chk[i]) continue;
        while(2 * i < p) p >>= 1;
        chk[i] = chk[p - i - 1] = true;
        ans.push_back({i, p - i - 1});
      }
      for(auto v: ans) cout << v.first << ' ';
      for (auto v : ans) cout << v.second << ' ';
      cout << '\n';
      for (auto v : ans) cout << v.second << ' ';
      for (auto v : ans) cout << v.first << ' ';
      cout << '\n';
    }
  }
}