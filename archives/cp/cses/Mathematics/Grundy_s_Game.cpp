#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  const int N = 2000;
  vector<int> dp(N);
  dp[0] = 0, dp[1] = 0, dp[2] = 0;
  for (int i = 2; i < N; ++i) {
    set<int> s;
    for (int j = 1; j < i - j; ++j) {
      s.insert(dp[j] ^ dp[i - j]);
    }
    for (int j = 0; j < N; ++j) {
      if (!s.count(j)) {
        dp[i] = j;
        break;
      }
    }
  }
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    if (n < 2000)
      cout << (dp[n] ? "first" : "second") << '\n';
    else
      cout << "first\n";
  }
}