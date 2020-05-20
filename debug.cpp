#include <boost/format.hpp>
#include <boost/tuple/tuple_io.hpp>
using namespace std;

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
template<typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &s) {
  if (s.empty()) return os << "set{}";
  os << "set{" << *s.begin();
  for (auto it = ++s.begin(); it != s.end(); ++it)
    os << ", " << *it;
  return os << "}";
}
template<typename S, typename T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &m) {
  if (m.empty()) return os << "map{}";
  os << "map{" << (*m.begin()).first << ": " << (*m.begin()).second;
  for (auto it = ++m.begin(); it != m.end(); ++it)
    os << ", " << (*it).first << ": " << (*it).second;
  return os << "}";
}
template<typename T>
ostream &operator<<(ostream &os, const deque<T> &q) {
  if (q.empty()) return os << "deque{}";
  os << "deque{" << *q.begin();
  for (auto it = ++q.begin(); it != q.end(); ++it)
    os << ", " << *it;
  return os << "}";
}
template<typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "pair{" << p.first << ", " << p.second << "}";
}

// https://stackoverflow.com/a/29224175
template<typename StdTuple, std::size_t... Is>
auto to_boost_tuple(StdTuple &&stdTuple, std::index_sequence<Is...>) {
  return boost::tuple<std::tuple_element_t<Is, std::decay_t<StdTuple>>...>
      (std::get<Is>(std::forward<StdTuple>(stdTuple))...);
}
template<typename StdTuple>
auto to_boost_tuple(StdTuple &&stdTuple) {
  return to_boost_tuple(std::forward<StdTuple>(stdTuple),
                        std::make_index_sequence<std::tuple_size<std::decay_t<StdTuple>>::value>());
}
template<typename ...T>
ostream &operator<<(ostream &os, const tuple<T...> &t) {
  // boost::tuple はそのまんま出力できる
  return cout << to_boost_tuple(t);
}

/**
 * 2 進数表記
 * @tparam T
 * @param value
 */
template<typename T>
string bin(T value) {
  return bitset<sizeof(value) * CHAR_BIT>(value).to_string();
}
