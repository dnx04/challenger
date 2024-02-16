#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<int> p(n);
  for(auto &x: p) cin >> x, --x;
  vector<int> a(n), b(n);
  for(int i = 0; i < n; ++i) a[i] = n * i + 1;
  for(int i = 0; i < n; ++i) b[p[i]] = n * n + i - a[p[i]];
  for(auto x: a) cout << x << ' ';
  cout << '\n';
  for(auto x: b) cout << x << ' ';
}