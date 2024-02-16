#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (abs(a - 1) < abs(b - c) + abs(c - 1))
      cout << "1\n";
    else if (abs(a - 1) > abs(b - c) + abs(c - 1))
      cout << "2\n";
    else
      cout << "3\n";
  }
}