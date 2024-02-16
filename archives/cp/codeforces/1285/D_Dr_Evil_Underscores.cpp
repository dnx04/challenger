#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "lib/prettyprint.hpp"
#endif

const int N = 2e5 + 1;

int rec(vector<int> &c, int bit) {
  if (bit < 0) return 0;
  vector<int> l, r;
  for (auto &x : c) {
    if ((x >> bit) & 1)
      r.push_back(x);
    else
      l.push_back(x);
  }
  if (l.empty()) return rec(r, bit - 1);
  else if (r.empty()) return rec(l, bit - 1);
  else return min(rec(l, bit - 1), rec(r, bit - 1)) + (1 << bit);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  cout << rec(a, 30);
}