#include "bits/extc++.h"

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#ifdef DEBUG
#include "tools/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  unordered_map<char, int> mp;
  for (int i = 'a'; i <= 'z'; ++i) mp[i] = i - 'a';
  for (int i = '0'; i <= '9'; ++i) mp[i] = 26 + i - '0';
  using ll = long long;
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    char ch;
    cin >> ch;
    a[i] = a[i - 1] ^ (1ll << mp[ch]);
  }
  map<ll, ll> cnt[2];
  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans += cnt[i & 1][a[i]];
    for (int j = 0; j < 36; ++j) ans += cnt[1 - (i & 1)][a[i] ^ (1ll << j)];
    ++cnt[i & 1][a[i]];
  }
  cout << ans;
}