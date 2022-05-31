#include <bits/stdc++.h>

using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        int ptr = 0;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            int x;
            cin >> x;
            ptr = (ptr + x) % n;
        }
        cout << a[ptr] << '\n';
    }
}