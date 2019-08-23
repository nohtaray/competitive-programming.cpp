#include <bits/stdc++.h>
using namespace std;

/**
 * http://hos.ac/slides/20140319_bit.pdf
 */
class BinaryIndexedTree {
 private:
  vector<long long> bit;
  unsigned long long size;

 public:
  explicit BinaryIndexedTree(unsigned long long size) : bit(size + 1, 0), size(size) {}

  /**
   * @param i
   * @param value
   */
  void add(unsigned long long i, long long value) {
    for (unsigned long long x = i; x < size; x |= x + 1) {
      bit[x] += value;
    }
  }

  /**
   * [0, i) の合計
   * @param i
   */
  long long sum(unsigned long long i) {
    if (i == 0) return 0;

    long long ret = 0;
    for (long long x = (long long) i - 1; x >= 0; x = (x & (x + 1)) - 1) {
      ret += bit[x];
    }
    return ret;
  }
};
