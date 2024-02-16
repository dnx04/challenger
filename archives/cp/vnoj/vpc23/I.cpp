#line 1 "I.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 1 "algo/graph/bipartite_matching.hpp"
// Max Bipartite matching.
// Index from 0
// Assume 2 sides have same number of vertices
//
// Notes:
// - If TLE --> try shuffle edges
//   REP(i,n) shuffle(ke[i].begin(), ke[i].end(), rng)
// - It should be quite fast, can AC 10^5 vertices

struct bipartite_matching {
  int n;
  vector<vector<int> > ke;
  vector<int> seen;
  vector<int> matchL, matchR;
  int iteration;

  bipartite_matching(int _n)
      : n(_n),
        ke(_n),
        seen(_n, false),
        matchL(_n, -1),
        matchR(_n, -1),
        iteration{0} {}

  void add_edge(int u, int v) { ke[u].push_back(v); }

  bool dfs(int u) {
    seen[u] = iteration;
    for (int v : ke[u]) {
      if (matchR[v] < 0) {
        matchR[v] = u;
        matchL[u] = v;
        return true;
      }
    }
    for (int v : ke[u]) {
      if (seen[matchR[v]] != iteration && dfs(matchR[v])) {
        matchR[v] = u;
        matchL[u] = v;
        return true;
      }
    }
    return false;
  }

  int match() {
    int res = 0;
    int newMatches = 0;
    do {
      iteration++;
      newMatches = 0;
      for (int u = 0; u < n; u++) {
        if (matchL[u] < 0 && dfs(u)) ++newMatches;
      }
      res += newMatches;
    } while (newMatches > 0);
    return res;
  }
};
#line 9 "I.cpp"

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);

  const int MAX = 3e8;

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> p(k), q(k), idx(n + 1);
  vector<vector<int>> d(n + 1, vector<int>(n + 1, MAX));
  for (int i = 1; i <= n; ++i) d[i][i] = 0;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    d[u][v] = w;
    d[v][u] = w;
  }
  for (int i = 0; i < k; ++i) cin >> p[i], idx[p[i]] = i + 1;
  for (int i = 0; i < k; ++i) cin >> q[i];

  // part 2: apsp
  for (int x = 1; x <= n; ++x) {
    for (int u = 1; u <= n; ++u) {
      for (int v = 1; v <= n; ++v) {
        d[u][v] = min(d[u][v], d[u][x] + d[x][v]);
      }
    }
  }
  vector<tuple<int, int, int>> edges;
  for (auto pi : p) {
    for (auto qi : q) {
      edges.emplace_back(d[pi][qi], pi, qi);
    }
  }

  // part 3: binary search + matching
  sort(edges.begin(), edges.end());
  int lo = 0, hi = MAX;
  bipartite_matching ans(n + 1);
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    bipartite_matching bm(n + 1);
    for (auto [w, u, v] : edges) {
      if (w <= mid) bm.add_edge(u, v);
    }
    if (bm.match() == k) {
      hi = mid;
      ans = bm;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << '\n';
  for(int i = 0; i < k; ++i) cout << idx[ans.matchR[q[i]]] << ' ';
}
