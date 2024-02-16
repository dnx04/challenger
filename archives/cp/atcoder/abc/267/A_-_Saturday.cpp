#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  map<string, int> d({{"Monday", 5},
                      {"Tuesday", 4},
                      {"Wednesday", 3},
                      {"Thursday", 2},
                      {"Friday", 1}});
  string s;
  cin >> s;
  cout << d[s];
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}