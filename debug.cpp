#include <bits/stdc++.h>
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
template<typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "pair{" << p.first << ", " << p.second << "}";
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
