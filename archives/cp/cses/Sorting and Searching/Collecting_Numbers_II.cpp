#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1), pos(n + 2);
  for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]] = i;
  pos[n + 1] = n + 1;
  int ans = 1;
  for (int i = 1, l = 1; i <= n; ++i) {
    if (l > pos[i]) ++ans;
    l = pos[i];
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    int r = a[x], s = a[y];
    swap(a[x], a[y]);
    if (pos[r - 1] <= pos[r] && pos[r - 1] > y) ++ans;
    if (pos[r - 1] > pos[r] && pos[r - 1] <= y) --ans;
    if (pos[r] <= pos[r + 1] && y > pos[r + 1]) ++ans;
    if (pos[r] > pos[r + 1] && y <= pos[r + 1]) --ans;
    pos[r] = y;
    if (pos[s - 1] <= pos[s] && pos[s - 1] > x) ++ans;
    if (pos[s - 1] > pos[s] && pos[s - 1] <= x) --ans;
    if (pos[s] <= pos[s + 1] && x > pos[s + 1]) ++ans;
    if (pos[s] > pos[s + 1] && x <= pos[s + 1]) --ans;
    pos[s] = x;
    cout << ans << '\n';
  }
}