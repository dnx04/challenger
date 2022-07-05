#include "bits/extc++.h"

using namespace std;

#ifdef local
#include "lib/prettyprint.hpp"
#endif

signed main() {
  int n;
  cin >> n;
  auto ask = [](const vector<int> &a) {
    cout << "? ";
    for (auto v : a) cout << v << ' ';
    cout << endl;
  };
  auto res = [](int &res) { cin >> res; };
  auto ans = [](const vector<int> &a) {
    cout << "! ";
    for (auto v : a) cout << v << ' ';
    cout << endl;
  };
  vector<int> p(n), rep(n), rep2(n), nxt(n);
  for (int i = 0; i < n; ++i) {
    vector<int> q(n, 1);
    q[i] = 2;
    ask(q);
    res(rep[i]);
    --rep[i];
    if (rep[i] == -1) p[i] = n;
  }
  for (int i = 0; i < n; ++i) {
    vector<int> q(n, 2);
    q[i] = 1;
    ask(q);
    res(rep2[i]);
    --rep2[i];
    if (rep2[i] == -1) p[i] = 1;
  }
  int ptr = 0;
  for (int i = 0; i < n; ++i) {
    if (rep[i] != -1 && rep[i] < i) nxt[i] = rep[i];
    if (rep2[i] != -1 && rep2[i] < i) nxt[rep2[i]] = i;
    if (p[i] == 1) ptr = i;
  }
  int cnt = 1;
  while (p[ptr] != n) {
    ptr = nxt[ptr];
    p[ptr] = ++cnt;
  }
  ans(p);
}