#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  if (n == 0)
    cout << 0;
  else {
    string ans;
    while(n != 0){
      if(n % 2 == 0) ans += '0';
      else ans += '1', --n;
      n /= -2;
    }
    reverse(begin(ans), end(ans));
    cout << ans;
  }
}