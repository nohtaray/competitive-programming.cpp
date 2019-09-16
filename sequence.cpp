#include <bits/stdc++.h>
using namespace std;

/**
 * TODO: 逆順にソートできるようにしたい
 * @tparam T
 * @param vec
 */
template<typename T>
vector<unsigned long> argsort(const vector<T> &vec) {
  vector<pair<T, unsigned long>> values;
  vector<unsigned long> ret;

  for (unsigned long i = 0; i < vec.size(); ++i) values.emplace_back(vec[i], i);
  sort(values.begin(), values.end());
  for (const auto &item: values) ret.push_back(item.second);
  return ret;
}

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
