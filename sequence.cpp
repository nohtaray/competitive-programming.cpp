#include <bits/stdc++.h>
using namespace std;

/**
 * 座標圧縮
 * @tparam T
 * @param values
 * @param origin
 */
template<typename T>
vector<long long> compress(const vector<T> &values, long long origin = 0) {
  unordered_map<T, long long> idx;
  long long i = origin;
  for (auto &&v : set<T>(values.begin(), values.end())) {
    idx[v] = i++;
  }

  vector<long long> ret;
  for (auto &&v : values) {
    ret.push_back(idx[v]);
  }
  return ret;
}
