#include <bits/stdc++.h>
#include <boost/optional.hpp>

using namespace std;

boost::optional<long long> dijkstra(
    const vector<vector<tuple<long long, long long>>> &graph,
    long long from_i,
    long long to_i) {
  const long long INF = 1e18;

  vector<long long> dist(graph.size(), INF);
  dist[from_i] = 0;

  priority_queue<tuple<long long, long long>, vector<tuple<long long, long long>>, greater<>> que;
  que.push(make_tuple(0, from_i));
  while (!que.empty()) {
    long long d, v;
    tie(d, v) = que.top();
    que.pop();
    if (d > dist[v]) continue;
    if (v == to_i) return d;

    for (const auto &edge : graph[v]) {
      long long w, u;
      tie(u, w) = edge;
      if (d + w < dist[u]) {
        dist[u] = d + w;
        que.push(make_tuple(d + w, u));
      }
    }
  }

  if (dist[to_i] < INF) {
    return dist[to_i];
  } else {
    return boost::none;
  }
}

vector<long long> topological_sort(const vector<vector<long long>> &graph) {
  long long size = graph.size();

  // 入次数
  vector<long long> ins(size, 0);

  for (auto &&vs : graph) {
    for (auto &&v : vs) {
      ins[v]++;
    }
  }

  // 入次数がゼロのやつを集める
  vector<long long> zeros;
  for (long long v = 0; v < size; ++v) {
    if (ins[v] == 0) {
      zeros.push_back(v);
    }
  }

  // ゼロのやつから追加してく
  vector<long long> ret;
  while (!zeros.empty()) {
    long long v = zeros.back();
    zeros.pop_back();
    ret.push_back(v);
    for (auto &&u:  graph[v]) {
      ins[u]--;
      if (ins[u] == 0) {
        zeros.push_back(u);
      }
    }
  }
  // 閉路があると入次数が絶対ゼロにならない
  if (ret.size() != size) {
    throw invalid_argument("閉路があります");
  }

  return ret;
}
