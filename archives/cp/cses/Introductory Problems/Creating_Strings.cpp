#include <bits/stdc++.h>

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  string s;
  cin >> s;
  sort(begin(s), end(s));
  vector<string> str;
  do {
    str.push_back(s);
  } while (next_permutation(begin(s), end(s)));
  cout << str.size() << '\n';
  for (auto ele : str) cout << ele << '\n';
}