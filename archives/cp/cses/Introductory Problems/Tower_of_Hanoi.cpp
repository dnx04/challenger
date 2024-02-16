#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n;
  cin >> n;
  cout << (1 << n) - 1 << '\n';
  auto rec = [](auto rec, int a, int b, int c, int n) -> void {
    if (n == 0) return;
    rec(rec, a, c, b, n - 1);
    cout << a << ' ' << c << '\n';
    rec(rec, b, a, c, n - 1);
  };
  rec(rec, 1, 2, 3, n);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}