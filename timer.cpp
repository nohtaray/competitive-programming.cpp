#include <bits/stdc++.h>
#include <boost/format.hpp>
using namespace std;

/**
 * 処理時間を計る
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
