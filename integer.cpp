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
 * (a / b) % mod
 * @param a
 * @param b
 * @param mod
 */
long long div_mod(long long a, long long b, long long mod) {
  return a * mod_pow(b, mod - 2, mod) % mod;
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

/**
 * n の約数
 * @param n
 */
vector<long long> get_divisors(long long n) {
  vector<long long> ret;
  long long rt = (long long) sqrt(n) + 1;
  for (long long i = 1; i < rt; ++i) {
    if (n % i == 0) {
      ret.push_back(i);
      if (n / i != i) {
        ret.push_back(n / i);
      }
    }
  }
  return ret;
}