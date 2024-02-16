#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<set<int>> nadj(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    nadj[a].insert(b);
    nadj[b].insert(a);
  }
  set<int> nvis;
  for (int i = 0; i < n; ++i) nvis.insert(i);
  vector<int> cc;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (nvis.count(i)) {
      q.push(i);
      nvis.erase(i);
      int c = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        ++c;
        vector<int> to_erase;
        for (auto v : nvis) {
          if (!nadj[u].count(v)) {
            q.push(v);
            to_erase.push_back(v);
          }
        }
        for (int v : to_erase) nvis.erase(v);
      }
      cc.push_back(c);
    }
  }
  sort(begin(cc), end(cc));
  cout << cc.size() << '\n';
  for (auto sz : cc) cout << sz << ' ';
}