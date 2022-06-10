#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define _GLIBCXX_ASSERTIONS
#endif

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> s;
  multiset<int> mts;
  s.insert({0, n});
  mts.insert(n);
  for (int i = 0; i < m; ++i) {
    int p;
    cin >> p;
    auto itr = s.upper_bound({p, p});
    int l, r;
    tie(l, r) = *(--itr);
    s.erase(itr);
    s.insert({l, p});
    s.insert({p, r});
    mts.erase(mts.find(r - l));
    mts.insert(p - l);
    mts.insert(r - p);
    cout << *prev(end(mts)) << ' ';
  }
}