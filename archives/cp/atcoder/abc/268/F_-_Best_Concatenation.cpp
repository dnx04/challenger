#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n;
  cin >> n;
  vector<tuple<ll, ll, ll>> str(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    ll occX = 0, pts = 0, sum_num = 0;
    while (!s.empty()) {
      if (s.back() == 'X')
        ++occX, pts += sum_num;
      else
        sum_num += s.back() - '0';
      s.pop_back();
    }
    str[i] = {occX, sum_num, pts};
  }
  auto eval = [&](vector<tuple<ll, ll, ll>> str) -> ll {
    ll pts = 0, sum_num = 0;
    while (!str.empty()) {
      pts += get<0>(str.back()) * sum_num + get<2>(str.back());
      sum_num += get<1>(str.back());
      str.pop_back();
    }
    return pts;
  };
  sort(begin(str), end(str), [](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) {
    return get<0>(a) * get<1>(b) > get<0>(b) * get<1>(a);
  });
  cout << eval(str);
}