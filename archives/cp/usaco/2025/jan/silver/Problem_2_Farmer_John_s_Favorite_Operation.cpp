#include <bits/stdc++.h>

#ifdef LOCAL
#include "algo-ng/prettyprint.hpp"
#endif

using namespace std;

#define int long long
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int minOperationsToCongruent(vector<int>& A, int M) {
  if (M == 1) {
    return 0;  // All elements are already congruent modulo 1
  }

  int n = A.size();
  vector<int> remainders(n);
  for (int i = 0; i < n; ++i) {
    int rem = A[i] % M;
    if (rem < 0) rem += M;  // Ensure remainder is non-negative
    remainders[i] = rem;
  }

  sort(remainders.begin(), remainders.end());

  // Create S by duplicating and adding M
  vector<int> S = remainders;
  for (int r : remainders) {
    S.push_back(r + M);
  }

  // Compute prefix sums
  vector<long long> prefix(S.size() + 1, 0);
  for (int i = 0; i < S.size(); ++i) {
    prefix[i + 1] = prefix[i] + S[i];
  }

  long long minTotal = LLONG_MAX;

  // Slide window of size n
  for (int i = 0; i <= (int)S.size() - n; ++i) {
    int j = i + n;
    int m = i + (n - 1) / 2;  // Median index
    long long median = S[m];

    // Left sum: from i to m inclusive
    int leftCount = m - i + 1;
    long long leftSum = median * leftCount - (prefix[m + 1] - prefix[i]);

    // Right sum: from m+1 to j-1 inclusive
    int rightCount = j - (m + 1);
    long long rightSum = (prefix[j] - prefix[m + 1]) - median * rightCount;

    long long total = leftSum + rightSum;
    if (total < minTotal) {
      minTotal = total;
    }
  }

  return (int)minTotal;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vi a(n);
  rep(i, 0, n) cin >> a[i], a[i] %= m;
  cout << minOperationsToCongruent(a, m) << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve();
  }
}
