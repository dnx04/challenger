#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n;
  cin >> n;
  vector<int> a, b;
  if (n % 4 == 0) {
    for (int i = 1; i <= n; ++i) {
      if (i % 4 < 2)
        a.push_back(i);
      else
        b.push_back(i);
    }
    cout << "YES\n";
    cout << a.size() << '\n';
    for (auto v : a) cout << v << ' ';
    cout << '\n' << b.size() << '\n';
    for (auto v : b) cout << v << ' ';
  } else if (n % 4 == 3) {
    for (int i = 1; i < n; ++i) {
      if (i % 4 == 1 || i % 4 == 2)
        a.push_back(i);
      else
        b.push_back(i);
    }
    b.push_back(n);
    cout << "YES\n";
    cout << a.size() << '\n';
    for (auto v : a) cout << v << ' ';
    cout << '\n' << b.size() << '\n';
    for (auto v : b) cout << v << ' ';
  } else {
    cout << "NO";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}