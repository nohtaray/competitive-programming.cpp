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

/**
 * x ** y % mod
 * @param x
 * @param y
 * @param mod
 */
ll mod_pow(ll x, ll y, ll mod) {
  ll ret = 1;
  while (y > 0) {
    if (y & 1) {
      ret = ret * x % mod;
    }
    x = x * x % mod;
    y >>= 1;
  }
  return ret;
}

/**
 * 素因数分解
 * @param n
 */
vector<ll> get_factors(ll n) {
  vector<ll> ret;
  if (n <= 1) return ret;

  while (n > 2 && n % 2 == 0) {
    ret.push_back(2);
    n /= 2;
  }
  ll i = 3;
  while (pow(i, 2) <= n) {
    if (n % i == 0) {
      ret.push_back(i);
      n /= i;
    } else {
      i += 2;
    }
  }
  ret.push_back(n);
  return ret;
}
