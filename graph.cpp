#include <bits/stdc++.h>
using namespace std;

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
