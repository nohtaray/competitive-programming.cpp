#include <bits/stdc++.h>
using namespace std;

/**
 * 座標圧縮
 * values を 1 以上の整数に圧縮したベクタを生成する
 * @tparam T
 * @param values
 */
template<typename T>
vector<long long> compress(vector<T> &values) {
  vector<long long> ret(values.size());
  vector<pair<T, unsigned long long>> V(values.size());

  for (long long i = 0; i < values.size(); ++i) {
    V[i] = make_pair(values[i], i);
  }
  sort(V.begin(), V.end());

  long long cnt = 1;
  T prev = V[0].first;
  for (const auto &vi : V) {
    T v;
    long long i;
    tie(v, i) = vi;

    if (prev != v) cnt++;
    ret[i] = cnt;
    prev = v;
  }
  return ret;
}
