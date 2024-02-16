#line 1 "String_Matching.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 1 "algo/strings/kmp.hpp"
vector<int> kmp(const string &s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
#line 9 "String_Matching.cpp"

void solve([[maybe_unused]] int ith) {
  string s, p;
  cin >> s >> p;
  auto pi = kmp(p + '#' + s);
  cout << accumulate(begin(pi), end(pi), 0,
                     [&](int acc, int x) { return acc + (x == (int)p.size()); });
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}
