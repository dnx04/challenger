#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

const int N = 5000;
int64_t dp[N][N];
vector<int64_t> a(N);

int64_t rec(int l, int r) {
  int64_t &res = dp[l][r];
  if (res != -1) return res;
  if (l == r) return res = a[l];
  res = max(a[l] - rec(l + 1, r), a[r] - rec(l, r - 1));
  return res;
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  memset(dp, -1, sizeof dp);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  // x = (x + y + (x - y)) / 2
  cout << (accumulate(begin(a), begin(a) + n, 0ll) + rec(0, n - 1)) / 2;
}