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

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ifstream ifs;
  if (getenv("LOCAL") != nullptr) {
    ifs.open("src/_in.txt");
    cin.rdbuf(ifs.rdbuf());
  }

}