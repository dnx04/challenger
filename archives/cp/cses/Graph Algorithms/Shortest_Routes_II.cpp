#line 1 "Shortest_Routes_II.cpp"
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

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
#line 10 "Shortest_Routes_II.cpp"

void solve(int ith) {
  int n, m, q;
  cin >> n >> m >> q;
  const ll INF = 1ll << 60;
  Vec<2, ll> dp(n, n, INF);
  for (int i = 0; i < n; ++i) dp[i][i] = 0;
  for (int i = 0; i < m; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    --u, --v;
    dp[u][v] = min(dp[u][v], w);
    dp[v][u] = min(dp[v][u], w);
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    cout << (dp[u][v] == INF ? -1 : dp[u][v]) << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}
