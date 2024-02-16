#line 1 "Planets_and_Kingdoms.cpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

#line 2 "algo/graph/scc.hpp"

struct scc {
  vector<vector<int>> g;
  int n;
  vector<int> num, low, current, S;
  int counter;
  vector<int> id;
  vector<vector<int>> scc_graph;

  scc(int n)
      : g(n),
        n(n),
        num(n, -1),
        low(n, 0),
        current(n, 0),
        counter(0),
        id(n, -1) {}

  void add_edge(int u, int v) { g[u].push_back(v); }

  void dfs(int u) {
    low[u] = num[u] = counter++;
    S.push_back(u);
    current[u] = 1;
    for (auto v : g[u]) {
      if (num[v] == -1) dfs(v);
      if (current[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u]) {
      scc_graph.push_back(vector<int>());
      while (1) {
        int v = S.back();
        S.pop_back();
        current[v] = 0;
        scc_graph.back().push_back(v);
        id[v] = (int)scc_graph.size() - 1;
        if (u == v) break;
      }
    }
  }

  // build scc_graph
  void build() {
    for (int i = 0; i < n; i++) {
      if (num[i] == -1) dfs(i);
    }
    reverse(begin(scc_graph), end(scc_graph));
  }

  // build DAG of strongly connected components
  // Returns: adjacency list of DAG, and root vertices (in-degree
  // = 0)
  pair<vector<vector<int>>, vector<int>> condense() {
    vector<vector<int>> dag(scc_graph.size());
    vector<int> roots, in(scc_graph.size());
    for (int u = 0; u < n; ++u) {
      int x = id[u];
      for (int v : g[u]) {
        int y = id[v];
        if (x != y) {
          dag[x].push_back(y);
          ++in[y];
        }
      }
    }
    for (int u = 0; u < (int)dag.size(); ++u)
      if (in[u] == 0) roots.push_back(u);
    return {dag, roots};
  }
};
#line 9 "Planets_and_Kingdoms.cpp"

void solve([[maybe_unused]] int ith) {
  int n, m;
  cin >> n >> m;
  scc g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g.add_edge(--u, --v);
  }
  g.build();
  cout << g.scc_graph.size() << "\n";
  for (int i = 0; i < n; ++i) cout << g.id[i] + 1 << ' ';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cin.exceptions(cin.failbit);
  int tc = 1;
  // cin >> tc;
  for (int i = 1; i <= tc; ++i) solve(i);
}
