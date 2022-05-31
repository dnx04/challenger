#include <bits/stdc++.h>

using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> a[2];
        for (int p : {0, 1})
        {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i)
            {
                int x;
                cin >> x;
                a[p].push_back(x);
            }
            sort(begin(a[p]), end(a[p]));
        }
        int s1 = a[0].size() - 1, s2 = a[1].size() - 1;
        if (a[0][s1] < a[1][s2])
            cout << "Bob\nBob\n";
        else if (a[0][s1] > a[1][s2])
            cout << "Alice\nAlice\n";
        else
            cout << "Alice\nBob\n";
    }
}