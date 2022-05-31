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
    sort(a, a + n);
    int ans[n];
    for (int i = 0; i < n; ++i)
    {
      if (i & 1)
      {
        ans[i] = a[n / 2 + i / 2 + n % 2];
      }
      else
      {
        ans[i] = a[i / 2];
      }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i)
    {
      bool c1 = (ans[(i - 1 + n) % n] < ans[i]) && (ans[i] > ans[(i + 1) % n]);
      bool c2 = (ans[(i - 1 + n) % n] > ans[i]) && (ans[i] < ans[(i + 1) % n]);
      ok &= (c1 || c2);
    }
    if (ok)
    {
      cout << "YES\n";
      for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
    }
    else
    {
      cout << "NO\n";
    }
  }
}