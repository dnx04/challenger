#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n;
  cin >> n;
  vector<int> a;
  for (int i = n - 3; i >= 2; --i) a.push_back(i);
  a.push_back(n - 2);
  a.push_back(1);
  a.push_back(n - 1);
  a.push_back(n);
  for (auto v : a) cout << v << ' ';
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}