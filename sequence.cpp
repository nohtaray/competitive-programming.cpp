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

/**
 * 0 から max までの逆元
 * @param max
 * @param mod
 * @return
 */
vector<long long> mod_invs(long long max, long long mod) {
  vector<long long> invs(max + 1, 1);
  for (long long x = 2; x <= max; ++x) {
    invs[x] = (-(mod / x) * invs[mod % x]) % mod;
  }
  return invs;
}

/**
 * 階乗 0!, 1!, 2!, ..., max! の逆元
 * @param max
 * @param mod
 * @return
 */
vector<long long> factorial_invs(long long max, long long mod) {
  vector<long long> ret;
  long long r = 1;
  for (const auto &inv : mod_invs(max, mod)) {
    r = r * inv % mod;
    ret.push_back(r);
  }
  return ret;
}