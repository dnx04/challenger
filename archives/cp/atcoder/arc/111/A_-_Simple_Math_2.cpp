#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  // calculate a^b mod m
  auto pow_mod = [](ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
      if (b & 1) {
        res = res * a % m;
      }
      a = a * a % m;
      b >>= 1;
    }
    return res;
  };
  ll n, m;
  cin >> n >> m;
  cout << pow_mod(10, n, m * m) / m % m << '\n';
}