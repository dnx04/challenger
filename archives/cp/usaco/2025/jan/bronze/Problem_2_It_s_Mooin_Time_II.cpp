#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo-ng/prettyprint.hpp"
#endif

using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  int n;
  cin >> n;
  vi a(n);
  rep(i, 0, n) cin >> a[i], --a[i];
  vi occ(n);
  vector<bool> pick(n, false);
  for (int i = n - 1; i >= 0; --i) {
    ++occ[a[i]];
    if (occ[a[i]] == 2) pick[i] = true;
  }
//   cerr << pick << '\n';
  ll ans = 0;
  set<int> s;
  for (int i = 0; i < n; ++i) {
    if (pick[i]) {
      ans += sz(s);
      if (s.count(a[i])) --ans;
    }
    s.insert(a[i]);
    // cerr << s << '\n';
  }
  cout << ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
