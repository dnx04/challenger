#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (auto &x : s) cin >> x;
  sort(begin(s), end(s));
  int totl = 0;
  for (auto str : s) totl += str.size();

  set<string> st;
  for (int i = 0; i < m; ++i) {
    string str;
    cin >> str;
    st.insert(str);
  }
  vector<vector<int>> comb;
  auto gen = [&](auto gen, int n, int sz, vector<int> cur = {}) -> void {
    if (sz == 0) {
      comb.push_back(cur);
      return;
    }
    for (int i = 1; i <= n; ++i) {
      cur.push_back(i);
      gen(gen, n - i, sz - 1, cur);
      cur.pop_back();
    }
  };
  gen(gen, 16 - totl, n - 1);
  do {
    for (auto pos : comb) {
      string res;
      for (int i = 0; i < n; ++i) {
        res += s[i];
        if (i + 1 < n) res += string(pos[i], '_');
      }
      if (res.length() >= 3 && !st.count(res)) return cout << res, 0;
    }
  } while (next_permutation(begin(s), end(s)));
  cout << -1;
}