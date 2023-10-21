#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

unordered_map<string, string> parent;
unordered_map<string, int> rank_;
unordered_map<string, int> size_;

string find_set(string x) {
  if (parent[x] != x) {
    parent[x] = find_set(parent[x]);
  }
  return parent[x];
}

int union_set(string x, string y) {
  x = find_set(x);
  y = find_set(y);
  if (x == y) {
    return size_[y];
  }
  if (rank_[x] > rank_[y]) {
    swap(x, y);
  } else if (rank_[x] == rank_[y]) {
    ++rank_[y];
  }
  parent[x] = y;
  size_[y] += size_[x];
  return size_[y];
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    parent.clear();
    rank_.clear();
    size_.clear();
    int F;
    cin >> F;
    while (F--) {
      string x, y;
      cin >> x >> y;
      if (parent.count(x) == 0) {
        parent[x] = x;
        rank_[x] = 0;
        size_[x] = 1;
      }
      if (parent.count(y) == 0) {
        parent[y] = y;
        rank_[y] = 0;
        size_[y] = 1;
      }
      cout << union_set(x, y) << '\n';
    }
  }
  return 0;
}
