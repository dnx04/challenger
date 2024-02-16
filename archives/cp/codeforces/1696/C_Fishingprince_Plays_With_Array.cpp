#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve(int ith) {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int k;
  cin >> k;
  vector<int> b(k);
  for (auto &x : b) cin >> x;

  auto enc = [&](const vector<int> &a) {
    vector<pair<int, ll>> enc;  // segments in the form <p, k>, sum = p * m^k
    for (auto x : a) {
      int p = x, e = 0;
      while (p % m == 0) p /= m, ++e;
      if (!enc.empty() && enc.back().first == p)
        enc.back().second += 1ll * pow(m, e);
      else
        enc.emplace_back(p, 1ll * pow(m, e));
    }
    return enc;
  };
  if (enc(a) == enc(b))
    cout << "Yes\n";
  else
    cout << "No\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}