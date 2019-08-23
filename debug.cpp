#include <bits/stdc++.h>
using namespace std;

/**
 * 2 進数表記
 * @tparam T
 * @param value
 */
template<typename T>
string bin(T value) {
  return bitset<sizeof(value) * CHAR_BIT>(value).to_string();
}
