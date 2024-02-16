#line 1 "G_Triple_Index.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 2 "algo/misc/mo_algo.hpp"

struct mo_algo {
  int width;
  vector<int> left, right, order;

  mo_algo(int N, int Q) : order(Q) {
    width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));
    iota(begin(order), end(order), 0);
  }

  void insert(int l, int r) { /* [l, r) */
    left.emplace_back(l);
    right.emplace_back(r);
  }

  template <typename AL, typename AR, typename DL, typename DR, typename REM>
  void run(const AL &add_left, const AR &add_right, const DL &delete_left,
           const DR &delete_right, const REM &rem) {
    assert(left.size() == order.size());
    sort(begin(order), end(order), [&](int a, int b) {
      int ablock = left[a] / width, bblock = left[b] / width;
      if (ablock != bblock) return ablock < bblock;
      if (ablock & 1) return right[a] < right[b];
      return right[a] > right[b];
    });
    int nl = 0, nr = 0;
    for (auto idx : order) {
      while (nl > left[idx]) add_left(--nl);
      while (nr < right[idx]) add_right(nr++);
      while (nl < left[idx]) delete_left(nl++);
      while (nr > right[idx]) delete_right(--nr);
      rem(idx);
    }
  }
};

/**
 * @brief Mo's algorithm
 * @docs docs/misc/mo.md
 */
#line 9 "G_Triple_Index.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  const int N = 2e5 + 1;
  int n, q;
  cin >> n >> q;
  mo_algo mo(n, q);
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    mo.insert(l - 1, r);
  }
  vector<ll> cnt(N), qr(q);
  ll ans_now = 0;

  auto add = [&](int i) {
    ans_now += 1ll * cnt[a[i]] * (cnt[a[i]] - 1) / 2;
    ++cnt[a[i]];
  };
  auto del = [&](int i) {
    --cnt[a[i]];
    ans_now -= 1ll * cnt[a[i]] * (cnt[a[i]] - 1) / 2;
  };
  auto rem = [&](int i) { qr[i] = ans_now; };
  mo.run(add, add, del, del, rem);
  for (auto &i : qr) cout << i << '\n';
}
