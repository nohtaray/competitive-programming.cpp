/**
 * LCA ダブリング版
 * 構築 O(NlogN)、クエリ O(logN)
 * Verify: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4508184
 */
class LCA {
 private:
  vector<vector<ll>> graph;
  ll root;
  // 何回ダブリングするか
  ll height;
  // depths[v]: v の root からの距離
  vector<ll> depths;
  // parents[k][v]: 親に 2^k たどった頂点
  vector<vector<ll>> parents;

  void _init() {
    vector<bool> seen(graph.size(), false);
    _init_dfs(root, -1, 0, seen);

    // parents を初期化
    rep(k, height - 1)
    {
      rep(v, graph.size())
      {
        if (parents[k][v] < 0) {
          // 親がなければ -1
          parents[k + 1][v] = -1;
        } else {
          parents[k + 1][v] = parents[k][parents[k][v]];
        }
      }
    }
  }

  // depths と parents[0] を初期化
  void _init_dfs(ll v, ll p, ll d, vector<bool> &seen) {
    parents[0][v] = p;
    depths[v] = d;
    seen[v] = true;
    each(u, graph[v])
    {
      if (!seen[u]) {
        _init_dfs(u, v, d + 1, seen);
      }
    }
  }

 public:
  LCA(const vector<vector<ll>> &graph, ll root) : graph(graph), root(root) {
    height = 0;
    ll sz = graph.size();
    while (sz > 0) {
      sz /= 2;
      height += 1;
    }

    depths = vector<ll>(graph.size(), -1);
    parents = vector < vector < ll >> (height, vector<ll>(graph.size(), -1));

    _init();
  };

  /**
   * v と u の LCA
   * @param v
   * @param u
   */
  auto lca(ll v, ll u) -> ll {
    if (depths[u] > depths[v]) {
      swap(v, u);
    }
    rep(k, height)
    {
      if ((depths[v] - depths[u]) >> k & 1) {
        v = parents[k][v];
      }
    }
    if (v == u) return v;

    rrep(k, height)
    {
      if (parents[k][v] != parents[k][u]) {
        v = parents[k][v];
        u = parents[k][u];
      }
    }
    return parents[0][v];
  }

  /**
   * 2 頂点間の距離
   * @param v
   * @param u
   */
  auto distance(ll v, ll u) -> ll {
    return depths[v] + depths[u] - depths[lca(v, u)] * 2;
  }
};
