#include <bits/stdc++.h>
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define rep2(i, s, e) for (int (i) = (s); (i) < (int)(e); ++(i))
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const long long MOD = 1000000007;

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
