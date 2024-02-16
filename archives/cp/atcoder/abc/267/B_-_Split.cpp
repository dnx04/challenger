#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  string str;
  cin >> str;
  vector<int> s(10);
  for (int i = 0; i < 10; ++i) s[i] = str[i] - '0';
  if (!s[0]) {
    if (!s[3]) {
      bool l = (s[6]);
      bool r = (s[1] || s[2] || s[4] || s[5] || s[7] || s[8] || s[9]);
      if (l && r) {
        cout << "Yes";
        return;
      }
    }
    if (!s[1] && !s[7]) {
      bool l = (s[3] || s[6]);
      bool r = (s[2] || s[4] || s[5] || s[8] || s[9]);
      if (l && r) {
        cout << "Yes";
        return;
      }
    }
    if (!s[4]) {
      bool l = (s[1] || s[3] || s[6] || s[7]);
      bool r = (s[2] || s[5] || s[8] || s[9]);
      if (l && r) {
        cout << "Yes";
        return;
      }
    }
    if (!s[2] && !s[8]) {
      bool l = (s[1] || s[3] || s[4] || s[6] || s[7]);
      bool r = (s[5] || s[9]);
      if (l && r) {
        cout << "Yes";
        return;
      }
    }
    if (!s[5]) {
      bool l = (s[1] || s[2] || s[3] || s[4] || s[6] || s[7] || s[8]);
      bool r = (s[9]);
      if (l && r) {
        cout << "Yes";
        return;
      }
    }
  }
  cout << "No";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}