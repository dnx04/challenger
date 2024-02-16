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
    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
      if (a[i] > a[i + 1])
        ++ans, ++i;
    }
    cout << ans << '\n';
  }
}