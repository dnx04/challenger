#include <bits/extc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  set<char> lul;
  char ch;
  for (auto i : {1, 2, 3, 4}) cin >> ch, lul.insert(ch);
  cout << (int)lul.size() - 1 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}