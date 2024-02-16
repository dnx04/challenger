#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  auto ask = [&](int a, int b, int c, int d) {
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    int x;
    cin >> x;
    return x;
  };
  auto ans = [&](int x, int y) {
    cout << "! " << x << ' ' << y << endl;
    exit(0);
  };
  int n;
  cin >> n;
  int rx = 0, ry = 0;
  int l = 1, r = n;
  while (l < r){
    int mid = (l + r) / 2, cnt = (mid - l + 1);
    if(ask(1, n, l, mid) < cnt) r = mid;
    else l = mid + 1;
  }
  ry = l;
  l = 1, r = n;
  while (l < r){
    int mid = (l + r) / 2, cnt = (mid - l + 1);
    if(ask(l, mid, 1, n) < cnt) r = mid;
    else l = mid + 1;
  }
  rx = l;
  ans(rx, ry);
}