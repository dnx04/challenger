#include <bits/stdc++.h>
#include <string>

using namespace std;

signed main() {
    auto check = [](string x) {
        if(x.length() < 3) return false;
        auto inc = x, dec = x;
        sort(inc.begin(), inc.end());
        sort(dec.rbegin(), dec.rend());
        return !(inc == x || dec == x);
    };
    int cnt = 0;
    for(int i = 1;; ++i) {
        cnt += check(to_string(i));
        if(100 * cnt == 99 * i) {
            cout << i;
            return 0;
        }
    
    }
}
