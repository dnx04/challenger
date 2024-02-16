#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  const int K = 20, N = 1 << K;
  int n;
  cin >> n;
  vector<int> a(n), f(1 << K), g(1 << K);
  for (auto &x : a) {
    cin >> x;
    ++f[x], ++g[x];
  }
  for (int i = 0; i < K; ++i) {
    for (int msk = 0; msk < N; ++msk) {
      if (msk & (1 << i)) f[msk] += f[msk ^ (1 << i)];
      if ((msk & (1 << i)) == 0) g[msk] += g[msk ^ (1 << i)];
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << f[a[i]] << ' ' << g[a[i]] << ' ' << n - f[(N - 1) ^ a[i]] << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}