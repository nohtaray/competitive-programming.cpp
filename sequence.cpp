#include <bits/stdc++.h>
using namespace std;

/**
 * 逆順にするなら
 * auto idx = argsort<ll>(vec, [](const auto &a, const auto &b) { return b < a; });
 * みたいにする
 * @tparam T
 * @param vec
 * @param comparator
 */
template<typename T>
vector<long long> argsort(
    const vector<T> &vec,
    const function<bool(const T &, const T &)> &comparator = [](const auto &a, const auto &b) { return a < b; }) {
  vector<pair<T, long long>> values;
  vector<long long> ret;

  for (long long i = 0; i < vec.size(); ++i) values.emplace_back(vec[i], i);
  stable_sort(values.begin(), values.end(), [&comparator](const auto &a, const auto &b) {
    return comparator(a.first, b.first);
  });
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
 * 0!, 1!, 2!, ..., max!
 * @param max
 * @param mod
 * @return
 */
vector<long long> get_factorials(long long max, long long mod = 0) {
  vector<long long> ret(max + 1, 1);
  long long n = 1;
  if (mod > 0) {
    for (long long i = 1; i <= max; ++i) {
      n *= i;
      n %= mod;
      ret[i] = n;
    }
  } else {
    for (long long i = 1; i <= max; ++i) {
      n *= i;
      ret[i] = n;
    }
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
  invs[0] = 0;
  for (long long x = 2; x <= max; ++x) {
    invs[x] = (mod - mod / x) * invs[mod % x] % mod;
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