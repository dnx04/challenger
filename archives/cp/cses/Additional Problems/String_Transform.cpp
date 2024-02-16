#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  string s;
  cin >> s;
  vector<int> nex(s.size());
  iota(begin(nex), end(nex), 0);
  stable_sort(begin(nex), end(nex), [&s](int a, int b) { return s[a] < s[b]; });
  string ans;
  for (int i = nex[0]; i;) ans += s[i = nex[i]];
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}