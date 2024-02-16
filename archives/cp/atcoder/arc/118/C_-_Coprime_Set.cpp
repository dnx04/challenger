#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  set<int> s;
  const int N = 10000;
  for (int i = 2; i * 6 <= N; ++i) {
    if (i * 6 <= N) s.insert(i * 6);
    if (i * 10 <= N) s.insert(i * 10);
    if (i * 15 <= N) s.insert(i * 15);
  }
  vector<int> ans({6, 10, 15});
  for (auto v : s) {
    if ((int)ans.size() == n)
      break;
    else
      ans.push_back(v);
  }
  for (auto v : ans) cout << v << ' ';
}