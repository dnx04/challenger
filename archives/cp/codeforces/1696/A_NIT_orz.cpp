#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  int n, z;
  cin >> n >> z;
  vector<int> a(n);
  int ans = 0;
  for(auto &x: a) {
    cin >> x;
    ans = max(ans, x | z);
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}