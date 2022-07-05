#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

const int N = 2e5;
vector<int> g[N], x(N), c(N), sum_hatred(N);
bitset<N> chk;
stack<int> st;
int64_t ans = 0;

void dfs(int u) {
  chk[u] = true;
  st.push(u);
  for (auto v : g[u]) {
    if (chk[v]) {
      int mn = 1e9;
      bool cyc = false;
      while (!st.empty()) {
        int pick = st.top();
        st.pop();
        mn = min(mn, sum_hatred[pick]);
        if (pick == v) {
          cyc = true;
          break;
        }
      }
      ans += mn * cyc;
    } else {
      dfs(v);
    }
  }
}

signed main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    g[i].push_back(x[i]);
  }
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i <= n; ++i) sum_hatred[i] += c[i];

  for (int i = 1; i <= n; ++i) {
    if (!chk[i]) {
      st = stack<int>();
      dfs(i);
    }
  }
  cout << ans;
}