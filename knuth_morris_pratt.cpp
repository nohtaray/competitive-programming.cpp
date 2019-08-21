#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#define rep(i, n) repr((i), 0, (n))
#define repr(i, a, t) reps((i), (a), (t), 1)
#define reps(i, a, t, s) for (long long (i) = (a); (i) < (long long)(t); (i) += (s))
#define rrep(i, n) rrepr((i), (n) - 1, 0)
#define rrepr(i, a, t) rreps((i), (a), (t), 1)
#define rreps(i, a, t, s) for (long long (i) = (a); (i) >= (long long)(t); (i) -= (s))
#define each(v, c) for (auto &&(v) : (c))
using namespace std;
namespace mp = boost::multiprecision;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ml = mp::cpp_int;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

/**
 * https://ja.wikipedia.org/wiki/クヌース–モリス–プラット法
 * 文字列検索
 */
class KMP {
 private:
  string needle;
  vector<ll> kmp;

 public:
  explicit KMP(const string &needle) : needle(needle), kmp(needle.size() + 2, 0) {
    // 部分マッチテーブルを構築
    kmp[0] = -1;
    kmp[1] = 0;
    {
      ll i = 2;
      ll j = 0;
      while (i < needle.size()) {
        if (needle[i - 1] == needle[j]) {
          kmp.at(i++) = ++j;
        } else if (j > 0) {
          j = kmp.at(j);
        } else {
          kmp.at(i++) = 0;
        }
      }
    }
  }

  /**
   * @param haystack
   * @param m The position of the current character in haystack
   * @param i The position of the current character in needle
   */
  ll index_of(const string &haystack, ll m = 0, ll i = 0) {
    while (m + i < haystack.size()) {
      if (needle.at(i) == haystack.at(m + i)) {
        if (++i == needle.size()) {
          return m;
        }
      } else {
        m += i - kmp.at(i);
        if (i > 0) {
          i = kmp.at(i);
        }
      }
    }
    return -1;
  }

  /**
   * ret[i]: haystack[i] 以降の文字列の最初が needle と同じなら true
   * @param haystack
   */
  vector<ll> search(const string &haystack) {
    vector<ll> ret(haystack.size(), false);

    ll m = 0;
    ll i = 0;
    while (m + i < haystack.size()) {
      m = index_of(haystack, m, i);
      if (m < 0) break;
      ret.at(m) = true;
      m += needle.size() - kmp.at(needle.size() - 1) - 1;
      i = max(0ll, kmp.at(needle.size() - 1));
    }
    return ret;
  }
};
