#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  int n;
  cin >> n;
  vector<int> a(n);
  int xs = 0;
  for (auto &x : a) cin >> x, xs ^= x;
  if (n % 2 == 1)
    cout << "Win";
  else {
    for (auto v : a) {
      if (v == xs) {
        cout << "Win";
        return;
      }
    }
    cout << "Lose";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}