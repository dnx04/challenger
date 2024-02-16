#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  rope<int> r;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    r.push_back(x);
  }
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    cout << r[--p] << ' ';
    r.erase(r.mutable_begin() + p);
  }
}