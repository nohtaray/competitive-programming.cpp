#include <bits/stdc++.h>
using namespace std;

/**
 * fn の結果が最も小さくなるインデックスを三分探索する
 * @tparam T
 * @param fn
 * @param lo
 * @param hi
 */
template<typename T>
long long tleft(function<T(long long)> fn, long long lo, long long hi) {
  long long left = lo;
  long long right = hi;
  while (abs(right - left) >= 3) {
    T r1 = (left * 2 + right) / 3;
    T r2 = (left + right * 2) / 3;
    if (fn(r1) <= fn(r2)) {
      right = r2;
    } else {
      left = r1;
    }
  }
  if (left + 1 >= hi || fn(left) <= fn(left + 1)) {
    return left;
  }
  if (left + 2 >= hi || fn(left + 1) <= fn(left + 2)) {
    return left + 1;
  }
  return left + 2;
}
