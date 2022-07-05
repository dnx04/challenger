#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a <= 0 && 0 <= b)
    cout << "Zero";
  else if (a > 0)
    cout << "Positive";
  else {
    b = min(b, -1);
    if(abs(a - b) & 1) cout << "Positive";
    else cout << "Negative";
  }
}