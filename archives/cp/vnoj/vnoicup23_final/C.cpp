#include "bits/stdc++.h"

#ifdef LOCAL
#include "tools/prettyprint.hpp"
#endif

using namespace std;

signed main() {
  int n;
  cin >> n;
  vector<int> sub(n);
  for (int i = 0; i < n; ++i) {
    cout << "subtree " << i + 1 << endl;
    cin >> sub[i];
  }
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; ++i) p[i] = {sub[i], i + 1};
  sort(rbegin(p), rend(p));
  for (int i = 0; i + 1 < n; ++i) {
    auto [sz, id] = p[i + 1];
    if (sz * 2 < n) break;
    cout << "move " << id << endl;
    int rd;
    cin >> rd;
  }
  return cout << "found" << endl, 0;
}