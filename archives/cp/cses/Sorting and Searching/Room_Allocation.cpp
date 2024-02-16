#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 1; i <= n; ++i) pq.push(i);
  vector<int> ans(n);
  vector<tuple<int,int,int>> a;
  for(int i = 0; i < n; ++i){
    int l, r;
    cin >> l >> r;
    a.emplace_back(l, 0, i);
    a.emplace_back(r, 1, i);
  }
  sort(a.begin(), a.end());
  for(auto [x, y, z] : a){
    if(y == 0){
      ans[z] = pq.top();
      pq.pop();
    }else{
      pq.push(ans[z]);
    }
  }
  cout << *max_element(ans.begin(), ans.end()) << '\n';
  for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
}