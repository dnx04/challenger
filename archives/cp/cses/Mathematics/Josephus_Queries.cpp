#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n, k;
  cin >> n >> k;
  auto J = [](auto J, int n, int k) {
    if (n == 1) return 1;
    if (k <= (n + 1) / 2) {
      if (2 * k > n)
        return 2 * k % n;
      else
        return 2 * k;
    }

    int c = J(J, n >> 1, k - (n + 1) / 2);
    if (n & 1)
      return 2 * c + 1;
    else
      return 2 * c - 1;
  };
  cout << J(J, n, k) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}