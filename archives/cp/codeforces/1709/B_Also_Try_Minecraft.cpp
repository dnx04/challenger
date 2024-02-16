#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;

void solve(int ith) {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n + 2), pre(n + 2), suf(n + 2);
  for(int i = 1; i <= n; ++i) cin >> a[i];
  for(int i = 1; i + 1 <= n; ++i) pre[i + 1] = pre[i] + max(a[i] - a[i + 1], 0ll);
  for(int i = n - 1; i >= 1; --i) suf[i] = suf[i + 1] + max(a[i + 1] - a[i], 0ll);
  while(m--){
    int u, v;
    cin >> u >> v;
    if(u <= v) cout << pre[v] - pre[u] << '\n';
    else cout << suf[v] - suf[u] << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}