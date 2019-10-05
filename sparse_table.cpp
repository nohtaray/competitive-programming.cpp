#include <bits/stdc++.h>
#include <boost/optional.hpp>
using namespace std;

/**
 * 構築 O(NlogN)、クエリ O(1)
 * @tparam T
 */
template<typename T>
class SparseTable {
 private:
  vector<T> values;
  vector<vector<unsigned long>> table;
  vector<unsigned long> msb;
  function<T(T, T)> fn;

  static vector<vector<unsigned long >> build(const vector<T> &values, function<T(T, T)> fn) {
    unsigned long size = (unsigned long) log2(values.size()) + 1;

    vector<vector<unsigned long >> st(values.size(), vector<unsigned long>(size));
    for (unsigned long i = 0; i < values.size(); ++i) st[i][0] = i;
    for (unsigned long p = 1; p < size; ++p) {
      for (unsigned long i = 0; i < values.size(); ++i) {
        unsigned long q = min(i + (1 << (p - 1)), (unsigned long) values.size() - 1);
        unsigned long l = st[i][p - 1];
        unsigned long r = st[q][p - 1];
        if (values[l] == fn(values[l], values[r])) {
          st[i][p] = l;
        } else {
          st[i][p] = r;
        }
      }
    }
    return st;
  }

 public:
  SparseTable(const vector<T> &values, function<T(T, T)> fn) {
    this->values = values;
    this->fn = fn;

    // table[i][p]: [i, i + 2^p) に fn を適用した結果の値のインデックス
    table = build(values, fn);

    // msb[i]: 最上位ビット; どの p を見るべきか
    msb = vector<unsigned long>(values.size() + 1);
    for (unsigned long i = 2; i < values.size() + 1; ++i) {
      msb[i] = msb[i >> 1] + 1;
    }
  }

  /**
   * [a, b) に fn を適用した結果
   */
  T get(unsigned long a, unsigned long b) {
    if (b <= a) throw invalid_argument("a < b でないといけません");
    if (b > values.size()) throw invalid_argument("範囲外です");
    unsigned long p = msb[b - a];
    return fn(values[table[a][p]], values[table[b - (1 << p)][p]]);
  }
};
