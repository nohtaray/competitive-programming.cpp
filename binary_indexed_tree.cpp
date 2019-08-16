#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

/**
 * http://hos.ac/slides/20140319_bit.pdf
 */
class BinaryIndexedTree {
 private:
  vector<ll> bit;
  ull size;

 public:
  explicit BinaryIndexedTree(ull size) : bit(size + 1, 0), size(size) {}

  /**
   * @param i
   * @param value
   */
  void add(ull i, ll value) {
    for (ull x = i; x < size; x |= x + 1) {
      bit[x] += value;
    }
  }

  /**
   * [0, i) の合計
   * @param i
   */
  ll sum(ull i) {
    ll ret = 0;
    for (ll x = i - 1; x >= 0; x = (x & (x + 1)) - 1) {
      ret += bit[x];
    }
    return ret;
  }
};
