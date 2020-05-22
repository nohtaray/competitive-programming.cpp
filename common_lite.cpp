#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <shared_mutex>
#include <any>
#include <charconv>
#include <filesystem>
#include <optional>
#include <string_view>
#include <variant>

#ifdef DEBUG
#include "libs/debug.cpp"
#define DEBUG 1
#else
#define DEBUG 0
#endif

#define rep(i, n) repr((i), 0, (n))
#define repr(i, a, t) reps((i), (a), (t), 1)
#define reps(i, a, t, s) for (long long (i) = (a); (i) < (long long)(t); (i) += (s))
#define rrep(i, n) rrepr((i), (n), 0)
#define rrepr(i, a, t) rreps((i), (a), (t), 1)
#define rreps(i, a, t, s) for (long long (i) = (a) - 1; (i) >= (long long)(t); (i) -= (s))
#define each(v, c) for (auto &&(v) : (c))
#define all(c) (c).begin(), (c).end()

using namespace std;

// コンテナのメンバ関数を使わないと O(N) おぼえたらけす
template<typename T>
typename set<T>::iterator lower_bound(typename set<T>::iterator l, typename set<T>::iterator r, const T &v);
template<typename T>
typename set<T>::iterator upper_bound(typename set<T>::iterator l, typename set<T>::iterator r, const T &v);
template<typename S, typename T>
typename map<S, T>::iterator lower_bound(typename map<S, T>::iterator l, typename map<S, T>::iterator r, const T &v);
template<typename S, typename T>
typename map<S, T>::iterator upper_bound(typename map<S, T>::iterator l, typename map<S, T>::iterator r, const T &v);

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

int main() {
  cout << fixed << setprecision(10);
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ifstream ifs;
  if (DEBUG) {
    ifs.open("src/_in.txt");
    cin.rdbuf(ifs.rdbuf());
  }

}