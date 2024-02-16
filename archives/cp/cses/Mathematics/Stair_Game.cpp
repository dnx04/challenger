#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve([[maybe_unused]] int ith) {
  int n;
  cin >> n;
  int xs = 0;
  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;
    if(i % 2 == 1) xs ^= x;
  }
  cout << (xs == 0 ? "second\n" : "first\n");
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}