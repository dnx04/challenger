#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n;
  cin >> n;
  map<string, int> cnta, cntb;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    ++cnta[s];
  }
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    ++cntb[s];
  }
  int ans = 0;
  for (auto &[s, cnt] : cnta) {
    int mn = min(cnt, cntb[s]);
    cnt -= mn;
    cntb[s] -= mn;
  }
  for (auto &[s, cnt] : cnta) {
    if (s.length() >= 2) {
      cnta[to_string(s.length())] += cnt;
      ans += cnt;
      cnt = 0;
    }
  }
  for (auto &[s, cnt] : cntb) {
    if (s.length() >= 2) {
      cntb[to_string(s.length())] += cnt;
      ans += cnt;
      cnt = 0;
    }
  }
  for (int i = 2; i <= 9; ++i) {
    auto si = to_string(i);
    int mn = min(cnta[si], cntb[si]);
    cnta[si] -= mn;
    cntb[si] -= mn;
  }
  for (auto &[s, cnt] : cnta)
    if (s != "1") ans += cnt;
  for (auto &[s, cnt] : cntb)
    if (s != "1") ans += cnt;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}