#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    int n, x;
    cin >> n >> x;
    const int MAX = pow(10, n - 1);
    map<int, int> mp;
    queue<int> q;

    mp[x] = 0;
    q.push(x);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        int step = mp[now];
        if (now >= MAX)
        {
            cout << step;
            return 0;
        }
        int tmp = now;
        while (tmp > 0)
        {
            int d = tmp % 10;
            if (d >= 2 && !mp.count(now * d))
            {
                mp[now * d] = step + 1;
                q.push(now * d);
            }
            tmp /= 10;
        }
    }
    cout << -1;
}