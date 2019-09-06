#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Counter {
 private:
  unordered_map<T, long long> counts;

  static bool compare(const pair<T, long long> &a, const pair<T, long long> &b) {
    if (a.second != b.second) {
      return a.second > b.second;
    } else {
      return a.first < b.first;
    }
  }

 public:
  explicit Counter(vector<T> &values) {
    for (auto &&v: values) {
      if (counts.count(v)) {
        counts[v]++;
      } else {
        counts[v] = 1;
      }
    }
  }

  unordered_map<T, long long> values() {
    return counts;
  }

  vector<pair<T, long long>> most_common() {
    vector<pair<T, long long>> ret;
    for (auto &&item: counts) {
      ret.emplace_back(item.first, item.second);
    }
    sort(ret.begin(), ret.end(), compare);
    return ret;
  }
};
