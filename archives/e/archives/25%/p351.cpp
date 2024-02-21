#include <bits/extc++.h>

using namespace std;

using ll = long long;

ll p351(int n){
    vector<ll> dp(n + 1);
    for(int i = 1; i <= n; ++i){
        ll nb = 6 * i - dp[i];
        for(int j = 2 * i; j <= n; j += i)
            dp[j] += nb;
    }
    return accumulate(dp.begin(), dp.end(), 0LL);
}

signed main(){
    cout << p351(100000000);
}