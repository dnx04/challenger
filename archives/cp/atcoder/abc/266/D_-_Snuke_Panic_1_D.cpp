#line 1 "D_-_Snuke_Panic_1_D.cpp"
#include <bits/extc++.h>

using namespace std;

using ll = long long;

#line 1 "algo/misc/vec.hpp"
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Dimension must be positive");
  template <typename... Args>
  Vec(int n = 0, Args... args)
      : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};

template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, T val = T()) : vector<T>(n, val) {}
};
#line 8 "D_-_Snuke_Panic_1_D.cpp"

void solve(int ith) {
  const int N = 1e5 + 5;
  Vec<2, ll> dp(N, 4), spawn(N, 4);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t, x;
    cin >> t >> x;
    cin >> spawn[t][x];
  }
  for (int t = 0; t + 1 < N; ++t) {
    for (int j = 0; j <= min(t, 4); ++j) {
      for (int d : {-1, 0, 1}) {
        if (j + d < 0 || j + d > 4) continue;
        dp[t + 1][j + d] =
            max(dp[t + 1][j + d], dp[t][j] + spawn[t + 1][j + d]);
      }
    }
  }
  cout << *max_element(begin(dp[N - 1]), end(dp[N - 1]));
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}
