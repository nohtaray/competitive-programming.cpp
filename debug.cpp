#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, e) for (int i = (s); i < (int)(e); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

/**
 * 2 進数表記
 * @tparam T
 * @param value
 */
template<typename T>
string bin(T value) {
  return bitset<sizeof(value) * CHAR_BIT>(value).to_string();
}
