#include <bits/stdc++.h>
#include "sequence.cpp"
using namespace std;

class Combination {
 private:
  vector<long long> factorials;
  vector<long long> finvs;
  ll mod;

 public:
  Combination(ll max, ll mod) : mod(mod) {
    factorials = get_factorials(max, mod);
    finvs = factorial_invs(max, mod);
  }

  long long ncr(ll n, ll r) {
    if (r < 0 || n < r) {
      return 0;
    }
    return factorials[n] * finvs[r] % mod * finvs[n - r] % mod;
  }
};
