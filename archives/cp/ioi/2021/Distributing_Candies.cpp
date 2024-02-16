#line 1 "main.cpp"
#include <bits/extc++.h>

using namespace std;

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
#line 6 "main.cpp"

using Query = tuple<int, int, int>;

const long long INF = static_cast<long long>(2e18);
struct S {
  long long suf_min, suf_max;
};
S op(S left, S right) {
  return S{
      std::min(left.suf_min, right.suf_min),
      std::max(left.suf_max, right.suf_max),
  };
};
S e() { return S{INF, -INF}; }
S mapping(long long f, S s) { return S{f + s.suf_min, f + s.suf_max}; }
long long composition(long long f, long long g) { return f + g; }
long long id() { return 0; }

std::vector<int> sub5(const std::vector<int>& c,
                      const std::vector<Query>& queries) {
  std::vector<std::vector<std::pair<int, long long> > > addAt(c.size()),
      removeAt(c.size());
  for (int i = 0; i < (int)queries.size(); ++i) {
    auto [l, r, v] = queries[i];
    addAt[l].push_back({i, v});
    removeAt[r].push_back({i, -v});
  }

  int q = queries.size();
  lazy_segtree<S, op, e, long long, mapping, composition, id> st(
      std::vector<S>(q + 1, {0, 0}));
  std::vector<int> a(c.size());
  for (int i = 0; i < (int)a.size(); ++i) {
    for (auto [queryId, val] : addAt[i]) {
      st.apply(queryId + 1, q + 1, val);
    }

    auto suffix_max = [&](int i) { return st.prod(i, q + 1).suf_max; };
    auto suffix_min = [&](int i) { return st.prod(i, q + 1).suf_min; };
    auto sum_v = [&](int i) { return st.get(i).suf_min; };

    // find last index t where suffix_max(t) - suffix_min(t) > c[i]
    auto r = std::views::iota(0, q + 1);
    auto res = std::ranges::partition_point(
        r, [&](int mid) { return suffix_max(mid) - suffix_min(mid) > c[i]; });

    if (res == r.begin())
      a[i] = sum_v(q) - suffix_min(0);
    else {
      --res;
      if (sum_v(*res) < sum_v(q)) {
        // currently touch lower bar, then finally touch upper bar once
        // after touching upper bar:
        // - upper bar will finally be at suffix_max[*res]
        // - final distance to upper bar is suffix_max[*res] - sum_vs
        a[i] = c[i] - (suffix_max(*res) - sum_v(q));
      } else {
        a[i] = sum_v(q) - suffix_min(*res);
      }
    }

    for (auto [queryId, val] : removeAt[i]) {
      st.apply(queryId + 1, q + 1, val);
    }
  }
  return a;
}

std::vector<int> distribute_candies(std::vector<int> c, std::vector<int> l,
                                    std::vector<int> r, std::vector<int> v) {
  int q = (int)l.size();
  std::vector<Query> queries;
  for (int i = 0; i < q; ++i) {
    queries.push_back({l[i], r[i], v[i]});
  }
  return sub5(c, queries);
}
