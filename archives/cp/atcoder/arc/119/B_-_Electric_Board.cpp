#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  string s, t;
  cin >> n >> s >> t;
  auto check = [](const string &s, const string &t) {
    string ss(s), tt(t);
    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());
    return ss == tt;
  };
  if(!check(s, t)) cout << -1;
  else {
    vector<int> ps, pt;
    for(int i = 0; i < n; ++i) if(s[i] == '0') ps.push_back(i);
    for(int i = 0; i < n; ++i) if(t[i] == '0') pt.push_back(i);
    int ans = 0;
    for(int i = 0; i < int(ps.size()); ++i) ans += ps[i] != pt[i];
    cout << ans;
  }
}