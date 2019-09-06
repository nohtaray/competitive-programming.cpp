#include <bits/stdc++.h>
#include <boost/optional.hpp>
using namespace std;

/**
 * http://tsutaj.hatenablog.com/entry/2017/03/29/204841
 */
template<typename T>
class SegmentTree {
 private:
  vector<T> nodes;
  unsigned long long size;
  function<T(T, T)> fn;

 public:
  explicit SegmentTree(
      unsigned long long size,
      function<T(T, T)> fn = [](T a, T b) { return a + b; },
      T initial = 0) {
    // size 以上の最小の2べき
    long long sz = 1;
    while (sz <= size) sz <<= 1;
    this->size = sz;

    // root が 1
    // i 番目の要素が size + i にある
    this->nodes = vector<T>(this->size * 2, initial);
    this->fn = fn;
  }

  /**
   * [from_i, to_i) に fn を適用した結果
   * @param from_i
   * @param to_i
   * @param k
   */
  boost::optional<T> get(
      unsigned long long from_i,
      unsigned long long to_i,
      unsigned long long k = 1,
      long long l = 0,
      long long r = -1) {
    if (r < 0) r = size;

    // 被覆してる
    if (from_i <= l && r <= to_i) return nodes[k];
    // 関係ない
    if (r <= from_i || to_i <= l) return boost::none;

    // 子からもらう
    boost::optional<T> left = get(from_i, to_i, k * 2, l, (l + r) / 2);
    boost::optional<T> right = get(from_i, to_i, k * 2 + 1, (l + r) / 2, r);

    if (left && right) return fn(*left, *right);
    if (left) return *left;
    if (right) return *right;
    return boost::none;
  }

  /**
   * i を value で更新する
   * @param i
   * @param value
   */
  void set(unsigned long long i, T value) {
    long long k = size + i;

    nodes[k] = value;
    k /= 2;
    while (k > 0) {
      nodes[k] = fn(nodes[k * 2], nodes[k * 2 + 1]);
      k /= 2;
    }
  }

  /**
   * もとの i 番目と value に fn を適用したものを i 番目に設定する
   * @param i
   * @param value
   */
  void add(unsigned long long i, T value) {
    long long k = size + i;
    set(i, fn(nodes[k], value));
  }
};
