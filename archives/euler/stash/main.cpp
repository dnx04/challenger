#include "bits/extc++.h"

using namespace std;

long long solve(int n) {
  long long ans = 0;
  vector<int> phi(n + 1);
  for (int i = 1; i <= n; ++i) phi[i] = i;
  for (int i = 3; i <= n; i += 2) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) {
        phi[j] -= phi[j] / i;
      }
    }
    ans += phi[i];
  }
  return ans + 1;
}

signed main() {
  cout << solve(500000000) << '\n';
}