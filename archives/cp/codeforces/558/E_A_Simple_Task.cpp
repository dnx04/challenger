#line 1 "E_A_Simple_Task.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 1 "algo/data-structure/lazy_segtree.hpp"
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S),
          F (*composition)(F, F), F (*id)()>
struct lazy_segtree {
 public:
  lazy_segtree() : lazy_segtree(0) {}
  explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n, e())) {}
  explicit lazy_segtree(const vector<S>& v) : n(int(v.size())) {
    log = ceil(log2(double(n)));
    size = 1 << log;
    d = vector<S>(2 * size, e());
    lz = vector<F>(size, id());
    for (int i = 0; i < n; i++) d[size + i] = v[i];
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  void set(int p, S x) {
    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = x;
    for (int i = 1; i <= log; i++) update(p >> i);
  }

  S get(int p) {
    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    return d[p];
  }

  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return e();

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    S sml = e(), smr = e();
    while (l < r) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
      l >>= 1;
      r >>= 1;
    }

    return op(sml, smr);
  }

  S all_prod() { return d[1]; }

  void apply(int p, F f) {
    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) push(p >> i);
    d[p] = mapping(f, d[p]);
    for (int i = 1; i <= log; i++) update(p >> i);
  }
  void apply(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return;

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    {
      int l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) all_apply(l++, f);
        if (r & 1) all_apply(--r, f);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  template <bool (*g)(S)>
  int max_right(int l) {
    return max_right(l, [](S x) { return g(x); });
  }
  template <class G>
  int max_right(int l, G g) {
    assert(0 <= l && l <= n);
    assert(g(e()));
    if (l == n) return n;
    l += size;
    for (int i = log; i >= 1; i--) push(l >> i);
    S sm = e();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!g(op(sm, d[l]))) {
        while (l < size) {
          push(l);
          l = (2 * l);
          if (g(op(sm, d[l]))) {
            sm = op(sm, d[l]);
            l++;
          }
        }
        return l - size;
      }
      sm = op(sm, d[l]);
      l++;
    } while ((l & -l) != l);
    return n;
  }

  template <bool (*g)(S)>
  int min_left(int r) {
    return min_left(r, [](S x) { return g(x); });
  }
  template <class G>
  int min_left(int r, G g) {
    assert(0 <= r && r <= n);
    assert(g(e()));
    if (r == 0) return 0;
    r += size;
    for (int i = log; i >= 1; i--) push((r - 1) >> i);
    S sm = e();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!g(op(d[r], sm))) {
        while (r < size) {
          push(r);
          r = (2 * r + 1);
          if (g(op(d[r], sm))) {
            sm = op(d[r], sm);
            r--;
          }
        }
        return r + 1 - size;
      }
      sm = op(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }

 private:
  int n, size, log;
  vector<S> d;
  vector<F> lz;

  void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void all_apply(int k, F f) {
    d[k] = mapping(f, d[k]);
    if (k < size) lz[k] = composition(f, lz[k]);
  }
  void push(int k) {
    all_apply(2 * k, lz[k]);
    all_apply(2 * k + 1, lz[k]);
    lz[k] = id();
  }
};
#line 9 "E_A_Simple_Task.cpp"

struct S {
  int sum, sz;
};
S op(S l, S r) { return S{l.sum + r.sum, l.sz + r.sz}; }
S e() { return S{0, 1}; }

const long long NOT_SET = -1;
struct F {
  int set, add;
};

S mapping(F f, S s) {
  if (f.set == NOT_SET) {
    return S{s.sum + f.add * s.sz, s.sz};
  }
  return S{(f.set + f.add) * s.sz, s.sz};
}
F composition(F f, F g) {
  if (f.set == NOT_SET) {
    return F{g.set, g.add + f.add};
  }
  return f;
}
F id() { return F{NOT_SET, 0}; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<lazy_segtree<S, op, e, F, mapping, composition, id>> segs(26);
  for (int i = 0; i < 26; i++) {
    segs[i] = lazy_segtree<S, op, e, F, mapping, composition, id>(n);
  }
  for (int i = 0; i < n; i++) segs[s[i] - 'a'].set(i, {1, 1});
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    --l, --r;
    vector<pair<char, int>> bucket;
    for (int i = 0; i < 26; ++i) {
      int cnt = segs[i].prod(l, r + 1).sum;
      if (cnt) bucket.emplace_back('a' + i, cnt);
    }
    if (x)
      sort(bucket.begin(), bucket.end());
    else
      sort(bucket.rbegin(), bucket.rend());
    for(int i = 0; i < 26; ++i) segs[i].apply(l, r + 1, {0, 0});
    for (auto [c, cnt] : bucket) {
      segs[c - 'a'].apply(l, l + cnt, {1, 0});
      l += cnt;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (segs[j].get(i).sum) {
        cout << char('a' + j);
        break;
      }
    }
  }
}
