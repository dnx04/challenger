#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc;
  cin >> tc;
  while (tc--) {
    string s;
    cin >> s;
    int n = s.length();
    int w, q;
    cin >> w >> q;
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + (s[i] - '0');
    auto get = [&](int l, int r) { return pre[r] - pre[l - 1]; };
    vector<pair<int, int>> pick(9, {-1, -1});
    for (int i = 1; i + w - 1 <= n; ++i) {
      int rem = get(i, i + w - 1) % 9;
      if (pick[rem].first != -1) {
        if (pick[rem].second == -1) {
          pick[rem].second = i;
        }
      } else {
        pick[rem].first = i;
      }
    }
    auto check = [&](pair<int, int> &ans, int l1, int l2) -> void {
      if (l1 != -1 && l2 != -1 && l1 != l2) {
        if (ans == make_pair(-1, -1)) {
          ans = {l1, l2};
          return;
        }
        if (l1 < ans.first) {
          ans = {l1, l2};
        } else if (l1 == ans.first) {
          if (l2 < ans.second) {
            ans = {l1, l2};
          }
        }
      }
    };
    for (int i = 1; i <= q; ++i) {
      int l, r, k;
      cin >> l >> r >> k;
      int vlr = get(l, r) % 9;
      pair<int, int> ans = {-1, -1};
      for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
          if ((i * vlr + j) % 9 == k) {
            check(ans, pick[i].first, pick[j].first);
            check(ans, pick[i].first, pick[j].second);
            check(ans, pick[i].second, pick[j].first);
            check(ans, pick[i].second, pick[j].second);
          }
        }
      }
      cout << ans.first << ' ' << ans.second << '\n';
    }
  }
}