#include "bits/extc++.h"

using namespace std;

#ifdef DEBUG
#include "tools/prettyprint.hpp"
#endif

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  auto ask = [&](int a, int b) { cout << "? " << a << " " << b << endl; };
  auto ans = [&](int x) { cout << "! " << x << endl; };
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); ++i) a[i] = i + 1;
    while (a.size() > 2) {
      vector<int> nxt;
      for (int i = 0; i < (int)a.size(); i += 4) {
        int res;
        ask(a[i], a[i + 2]);
        cin >> res;
        if (res == 0) {
          ask(a[i + 1], a[i + 3]);
          cin >> res;
          if (res == 1)
            nxt.push_back(a[i + 1]);
          else
            nxt.push_back(a[i + 3]);
        } else if (res == 1) {
          ask(a[i], a[i + 3]);
          cin >> res;
          if (res == 1)
            nxt.push_back(a[i]);
          else
            nxt.push_back(a[i + 3]);
        } else {
          ask(a[i + 1], a[i + 2]);
          cin >> res;
          if (res == 1)
            nxt.push_back(a[i + 1]);
          else
            nxt.push_back(a[i + 2]);
        }
      }
      a = nxt;
    }
    ask(a[0], a[1]);
    int res;
    cin >> res;
    ans((res == 1) ? a[0] : a[1]);
  }
}