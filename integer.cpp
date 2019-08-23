#include <bits/stdc++.h>
using namespace std;

/**
 * x ** y % mod
 * @param x
 * @param y
 * @param mod
 */
long long mod_pow(long long x, long long y, long long mod) {
  long long ret = 1;
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
vector<long long> get_factors(long long n) {
  vector<long long> ret;
  if (n <= 1) return ret;

  while (n > 2 && n % 2 == 0) {
    ret.push_back(2);
    n /= 2;
  }
  long long i = 3;
  while (i <= (long long) sqrt(n)) {
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
