#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  if (accumulate(begin(a), end(a), 0ll) == 0)
    cout << 0 << '\n';
  else {
    int seg = 0;
    int l = 0, r = n - 1;
    while (a[l] == 0 && l <= r) ++l;
    while (a[r] == 0 && l <= r) --r;
    bool lul = false;
    for (int i = l; i <= r; ++i) lul |= (a[i] == 0);
    if (lul)
      cout << 2 << '\n';
    else
      cout << 1 << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}