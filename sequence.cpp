#include <bits/stdc++.h>
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define rep2(i, s, e) for (int (i) = (s); (i) < (int)(e); ++(i))
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const long long MOD = 1000000007;

/**
 * 座標圧縮
 * values を 1 以上の整数に圧縮したベクタを生成する
 * @tparam T
 * @param values
 */
template<typename T>
vector<ll> compress(vector<T> &values) {
  vector<ll> ret(values.size());
  vector<pair<T, ull>> V(values.size());

  rep (i, values.size()) {
    V[i] = make_pair(values[i], i);
  }
  sort(V.begin(), V.end());

  ll cnt = 1;
  T prev = V[0].first;
  for (const auto &vi : V) {
    T v;
    ll i;
    tie(v, i) = vi;

    if (prev != v) cnt++;
    ret[i] = cnt;
    prev = v;
  }
  return ret;
}
