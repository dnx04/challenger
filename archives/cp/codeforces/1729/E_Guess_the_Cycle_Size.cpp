#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  auto ask = [&](int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    ll res;
    cin >> res;
    if (res == 0) exit(0);
    return res;
  };
  auto ans = [&](ll x) {
    cout << "! " << x << endl;
    exit(0);
  };
  const int mx = 50;
  for (int i = 2; i <= mx / 2 + 1; ++i) {
    ll res1 = ask(1, i);
    ll res2 = ask(i, 1);
    if (res1 == -1 || res2 == -1)
      ans(i - 1);
    else if (res1 != res2)
      ans(res1 + res2);
  }
}