#include <bits/stdc++.h>
#include <boost/format.hpp>
#include <boost/integer/common_factor_rt.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#define rep(i, n) repr((i), 0, (n))
#define repr(i, a, t) reps((i), (a), (t), 1)
#define reps(i, a, t, s) for (long long (i) = (a); (i) < (long long)(t); (i) += (s))
#define rrep(i, n) rrepr((i), (n) - 1, 0)
#define rrepr(i, a, t) rreps((i), (a), (t), 1)
#define rreps(i, a, t, s) for (long long (i) = (a); (i) >= (long long)(t); (i) -= (s))
#define each(v, c) for (auto &&(v) : (c))
#define all(c) (c).begin(), (c).end()
using namespace std;
namespace mp = boost::multiprecision;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using ml = mp::cpp_int;
template<typename T>
using optional = boost::optional<T>;
const auto none = boost::none;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (v.empty()) return os << "vector{}";
  os << "vector{" << *v.begin();
  for (auto it = ++v.begin(); it != v.end(); ++it)
    os << ", " << *it;
  return os << "}";
}
template<typename T>
ostream &operator<<(ostream &os, const set<T> &s) {
  if (s.empty()) return os << "set{}";
  os << "set{" << *s.begin();
  for (auto it = ++s.begin(); it != s.end(); ++it)
    os << ", " << *it;
  return os << "}";
}
template<typename S, typename T>
ostream &operator<<(ostream &os, const map<S, T> &m) {
  if (m.empty()) return os << "map{}";
  os << "map{" << (*m.begin()).first << ": " << (*m.begin()).second;
  for (auto it = ++m.begin(); it != m.end(); ++it)
    os << ", " << (*it).first << ": " << (*it).second;
  return os << "}";
}
template<typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "pair{" << p.first << ", " << p.second << "}";
}

int main() {
  cout << fixed << setprecision(10);
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ifstream ifs;
  if (getenv("LOCAL") != nullptr) {
    ifs.open("src/_in.txt");
    cin.rdbuf(ifs.rdbuf());
  }

}