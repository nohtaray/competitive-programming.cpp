#include <bits/stdc++.h>
using namespace std;

/**
 * https://ja.wikipedia.org/wiki/クヌース–モリス–プラット法
 * 文字列検索
 */
class KMP {
 private:
  string needle;
  vector<long long> kmp;

 public:
  explicit KMP(const string &needle) : needle(needle), kmp(needle.size() + 2, 0) {
    // 部分マッチテーブルを構築
    kmp[0] = -1;
    kmp[1] = 0;
    {
      long long i = 2;
      long long j = 0;
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
  long long index_of(const string &haystack, long long m = 0, long long i = 0) {
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
  vector<long long> search(const string &haystack) {
    vector<long long> ret(haystack.size(), false);

    long long m = 0;
    long long i = 0;
    while (m + i < haystack.size()) {
      m = index_of(haystack, m, i);
      if (m < 0) break;
      ret.at(m) = true;
      m += (long long) needle.size() - kmp.at(needle.size() - 1) - 1;
      i = max(0ll, kmp.at(needle.size() - 1));
    }
    return ret;
  }
};
