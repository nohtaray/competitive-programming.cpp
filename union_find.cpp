#include <bits/stdc++.h>
using namespace std;

class UnionFind {
 private:
  vector<unsigned long long> parents;
  vector<unsigned long long> ranks;
  vector<unsigned long long> sizes;

 public:
  explicit UnionFind(unsigned long long size) :
      parents(size),
      ranks(size, 0),
      sizes(size, 1) {
    for (unsigned long long i = 0; i < size; ++i) parents[i] = i;
  }

  void unite(unsigned long long x, unsigned long long y) {
    x = root(x);
    y = root(y);
    if (x == y) return;

    // rank が小さい方が下
    if (ranks[x] > ranks[y]) {
      // x が root
      parents[y] = x;
      sizes[x] += sizes[y];
    } else {
      // y が root
      parents[x] = y;
      sizes[y] += sizes[x];
      if (ranks[x] == ranks[y]) ranks[y]++;
    }
  }

  unsigned long long root(unsigned long long x) {
    if (parents[x] == x) return x;
    return parents[x] = root(parents[x]);
  }

  unsigned long long size(unsigned long long x) {
    return sizes[root(x)];
  }
};
