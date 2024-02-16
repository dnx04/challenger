#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

struct mex_array {
  map<int, int> frequency;
  set<int> missing_numbers;
  vector<int> A;

  mex_array(vector<int> const& A) : A(A) {
    for (int i = 0; i <= (int)A.size(); i++) missing_numbers.insert(i);

    for (int x : A) {
      ++frequency[x];
      missing_numbers.erase(x);
    }
  }

  int mex() { return *missing_numbers.begin(); }

  void update(int idx, int new_value) {
    if (--frequency[A[idx]] == 0) missing_numbers.insert(A[idx]);
    A[idx] = new_value;
    ++frequency[new_value];
    missing_numbers.erase(new_value);
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    mex_array ma(A);
    vector<int> ops;
    int unfixed = -1;
    while (true) {
      unfixed = -1;
      for (int i = 0; i < n; ++i) {
        if (ma.A[i] != i) {
          unfixed = i;
          break;
        }
      }
      if (unfixed == -1) break;
      if (ma.mex() == n) {
        ops.push_back(unfixed + 1);
        ma.update(unfixed, ma.mex());
      } else {
        ops.push_back(ma.mex() + 1);
        ma.update(ma.mex(), ma.mex());
      }
    }
    cout << ops.size() << '\n';
    for (int x : ops) cout << x << ' ';
    cout << '\n';
  }
}