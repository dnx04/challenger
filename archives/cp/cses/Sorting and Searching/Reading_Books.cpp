#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  /*
  think the order the two reads like cutting down two sticks into parts
  let mx the longest part
  then if 2 * mx > sum, then there will be overlap in their order of reading:
  e.g 1 2 4:
  p1: -++ xxxx
  p2: xxxx-++
  then the answer is 2 * mx
  else the answer is the sum
  e.g 1 2 3:
  p1: -++xxx
  p2: xxx-++
  */
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) cin >> x;
  ll mx = *max_element(a.begin(), a.end());
  ll sum = accumulate(a.begin(), a.end(), 0LL);
  cout << max(2 * mx, sum);
}