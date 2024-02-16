#include <bits/stdc++.h>

using namespace std;

signed main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    int sum = accumulate(a, a + n, 0);
    bool ok = false;
    for (int i = 0; i < n; ++i)
      ok |= (a[i] * n == sum);
    cout << (ok ? "yes\n" : "no\n");
  }
}