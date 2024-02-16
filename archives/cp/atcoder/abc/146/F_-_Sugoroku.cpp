#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  string s;
  const int inf = 1e9;
  cin >> n >> m >> s;
  vector<int> dist(n + 1, inf), max_left(n + 1, inf);
  dist[n] = 0;
  max_left[0] = n;
  int nxt = n - 1, left = n, timer = 0;
  while (true) {
    ++timer;
    int nleft = left;
    while (nxt >= left - m && nxt >= 0) {
      if (s[nxt] == '0') dist[nxt] = timer, nleft = nxt;
      --nxt;
    }
    if (nleft == left) return cout << -1, 0;
    left = nleft;
    max_left[timer] = left;
    if (nxt < 0) break;
  }
  vector<int> ans;
  int now = 0;
  while(timer){
    --timer;
    ans.push_back(max_left[timer] - now);
    now = max_left[timer];
  }
  for(auto v: ans) cout << v << ' ';
}