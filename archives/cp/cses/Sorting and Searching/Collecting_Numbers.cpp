#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  vector<int> pos(n + 1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    pos[x] = i;
  }
  pos[n + 1] = 0;  // beginning round
  int ans = 1;
  for (int i = 1; i < n; ++i)
    if (pos[i] > pos[i + 1]) ++ans;
  cout << ans;
}