#include <bits/stdc++.h>
using namespace std;

unsigned int randxor() {
  static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
  unsigned int t;
  t = (x ^ (x << 11));
  x = y;
  y = z;
  z = w;
  return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

/**
 * l 以上 r 以下の整数を返す
 * @param l
 * @param r
 */
int randint(int l, int r) {
  ld rnd = (ld) randxor() / UINT_MAX;
  rnd *= (r - l + 1);
  return int(rnd) + l;
}

/**
 * pair を map のキーにできるようにハッシュ化の方法を定義
 * https://www.techiedelight.com/use-std-pair-key-std-unordered_map-cpp/
 */
struct pair_hash {
  template<class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &pair) const {
    return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
  }
};

/**
 * 時間を計る
 * timer("<procedure name>", [&]{
 *   ...
 * });
 * @param name
 * @param fn
 */
void timer(string name, const function<void(void)> &fn) {
  auto st = chrono::system_clock::now();
  fn();
  auto now = chrono::system_clock::now();
  double t = chrono::duration_cast<chrono::milliseconds>(now - st).count();
  cerr << boost::format("[%s] %4d ms") % name % t << "\n";
}
