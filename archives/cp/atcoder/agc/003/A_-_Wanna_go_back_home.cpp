#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "lib/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int cs = 0, ce = 0, cn = 0, cw = 0;
  char ch;
  while (cin >> ch) {
    if (ch == 'S')
      ++cs;
    else if (ch == 'E')
      ++ce;
    else if (ch == 'N')
      ++cn;
    else
      ++cw;
  }
  bool okv = true, okh = true;
  okv &= ((cs == 0 && cn == 0) || (cs >= 1 && cn >= 1));
  okh &= ((ce == 0 && cw == 0) || (ce >= 1 && cw >= 1));
  if (okv && okh)
    cout << "Yes";
  else
    cout << "No";
}