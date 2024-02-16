// constructive problems are just time-consuming

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, x;
  cin >> n >> x;
  if (n % 2 == 1) {
    cout << x << ' ';
    for (int i = n / 2, j = n / 2 + 1; i > 0; i--, j++) {
      cout << (i + (i >= x ? 1 : 0)) << ' ' << (j + (j >= x ? 1 : 0)) << ' ';
    }
  } else {
    if (x == n / 2 + 1) {
      cout << x << ' ';
      for (int i = 1; i + 1 < x; i++) cout << x - i << ' ' << x + i << ' ';
      cout << 1;
      return 0;
    }
    cout << x << ' ' << n / 2 + (n / 2 >= x ? 1 : 0) << ' ';
    for (int i = n / 2 - 1, j = n / 2 + 1; i > 0; i--, j++)
      cout << i + (i >= x ? 1 : 0) << ' ' << j + (j >= x ? 1 : 0) << ' ';
  }
  return 0;
}