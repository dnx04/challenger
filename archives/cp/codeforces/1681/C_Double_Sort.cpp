#include <bits/stdc++.h>

using namespace std;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i].first;
        for (int i = 0; i < n; ++i)
            cin >> a[i].second;
        auto is_greater = [&](pair<int, int> &x, pair<int, int> &y)
        {
            if (x == y)
                return 0;
            else if (x.first >= y.first && x.second >= y.second)
                return 1;
            else if (x.first <= y.first && x.second <= y.second)
                return -1;
            else
                return -2;
        };
        vector<pair<int, int>> step;
        bool lmao = false;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (is_greater(a[i], a[j]) == -2)
                {
                    lmao = true;
                    break;
                }
                if (is_greater(a[i], a[j]) == 1)
                    step.push_back({i + 1, j + 1}), swap(a[i], a[j]);
            }
        }
        if (!lmao && is_sorted(begin(a), end(a)))
        {
            cout << step.size() << '\n';
            for (auto p : step)
                cout << p.first << ' ' << p.second << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
}